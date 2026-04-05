#!/usr/bin/env python3
"""
Nodo de aparcamiento para TurtleBot3.
Maniobra: avanzar hasta alinearse con la plaza, girar 90° a la derecha,
entrar en la plaza y detenerse al detectar la pared trasera.

Usa odometría para controlar distancias y giros, y el LiDAR para
detectar la apertura de la plaza y la pared trasera.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
import math
import time


class AparcamientoNode(Node):
    def __init__(self):
        super().__init__('aparcamiento')

        # Publisher de velocidad
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Subscribers
        self.odom_sub = self.create_subscription(Odometry, '/odom', self.odom_callback, 10)
        self.scan_sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)

        # Estado de odometría
        self.x = 0.0
        self.y = 0.0
        self.yaw = 0.0

        # Datos del LiDAR
        self.scan_data = None

        # Velocidades
        self.linear_speed = 0.15    # m/s
        self.angular_speed = 0.3    # rad/s

        # Distancia de seguridad a la pared trasera
        self.stop_distance = 0.35   # metros

        # Estado de la máquina de estados
        self.state = 'WAITING'
        self.start_x = 0.0
        self.start_y = 0.0
        self.start_yaw = 0.0

        # Timer principal (10 Hz)
        self.timer = self.create_timer(0.1, self.control_loop)

        self.get_logger().info('Nodo de aparcamiento iniciado. Esperando datos de sensores...')

    def odom_callback(self, msg):
        """Extrae posición y orientación (yaw) de la odometría."""
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y

        # Convertir quaternion a yaw
        q = msg.pose.pose.orientation
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        self.yaw = math.atan2(siny_cosp, cosy_cosp)

    def scan_callback(self, msg):
        """Almacena los datos del LiDAR."""
        self.scan_data = msg

    def get_front_distance(self):
        """Distancia al frente del robot (media de unos pocos rayos centrales)."""
        if self.scan_data is None:
            return float('inf')
        ranges = self.scan_data.ranges
        n = len(ranges)
        # Tomar rayos alrededor del índice 0 (frente)
        indices = list(range(0, 10)) + list(range(n - 10, n))
        valid = [r for i in indices if 0 < (r := ranges[i % n]) < self.scan_data.range_max]
        return min(valid) if valid else float('inf')

    def get_right_distance(self):
        """Distancia a la derecha del robot (alrededor de 270°)."""
        if self.scan_data is None:
            return float('inf')
        ranges = self.scan_data.ranges
        n = len(ranges)
        # 270° en el array (derecha del robot)
        center = int(n * 270 / 360)
        spread = 10
        indices = range(center - spread, center + spread)
        valid = [r for i in indices if 0 < (r := ranges[i % n]) < self.scan_data.range_max]
        return min(valid) if valid else float('inf')

    def get_distance_traveled(self):
        """Distancia recorrida desde el punto de inicio guardado."""
        dx = self.x - self.start_x
        dy = self.y - self.start_y
        return math.sqrt(dx * dx + dy * dy)

    def normalize_angle(self, angle):
        """Normaliza un ángulo al rango [-pi, pi]."""
        while angle > math.pi:
            angle -= 2.0 * math.pi
        while angle < -math.pi:
            angle += 2.0 * math.pi
        return angle

    def get_angle_turned(self):
        """Ángulo girado desde el inicio (normalizado)."""
        return abs(self.normalize_angle(self.yaw - self.start_yaw))

    def stop_robot(self):
        """Envía comando de parada."""
        twist = Twist()
        self.cmd_pub.publish(twist)

    def control_loop(self):
        """Máquina de estados principal."""
        # Esperar a tener datos de sensores
        if self.scan_data is None:
            return

        twist = Twist()

        if self.state == 'WAITING':
            # Iniciar la maniobra
            self.get_logger().info('Sensores listos. Iniciando maniobra de aparcamiento.')
            self.state = 'ADVANCE_TO_SPOT'
            self.start_x = self.x
            self.start_y = self.y
            self.start_yaw = self.yaw

        elif self.state == 'ADVANCE_TO_SPOT':
            # Avanzar hacia delante hasta pasar la plaza (detectar apertura a la derecha)
            right_dist = self.get_right_distance()
            front_dist = self.get_front_distance()
            distance_traveled = self.get_distance_traveled()

            self.get_logger().info(
                f'ADVANCE: dist_recorrida={distance_traveled:.2f}m, '
                f'derecha={right_dist:.2f}m, frente={front_dist:.2f}m'
            )

            # Avanzar una distancia fija para alinearse con la plaza
            # Ajusta este valor según la posición inicial del robot respecto a la plaza
            if distance_traveled < 1.5:
                twist.linear.x = self.linear_speed
            else:
                self.stop_robot()
                self.get_logger().info('Alineado con la plaza. Preparando giro.')
                self.state = 'TURN_RIGHT'
                self.start_yaw = self.yaw
                time.sleep(0.5)
                return

        elif self.state == 'TURN_RIGHT':
            # Girar 90° a la derecha (sentido horario = angular.z negativo)
            angle_turned = self.get_angle_turned()
            target_angle = math.pi / 2  # 90°

            self.get_logger().info(f'TURN: angulo_girado={math.degrees(angle_turned):.1f}°')

            if angle_turned < target_angle - 0.05:
                twist.angular.z = -self.angular_speed
            else:
                self.stop_robot()
                self.get_logger().info('Giro completado. Entrando en la plaza.')
                self.state = 'ENTER_SPOT'
                self.start_x = self.x
                self.start_y = self.y
                time.sleep(0.5)
                return

        elif self.state == 'ENTER_SPOT':
            # Avanzar dentro de la plaza hasta detectar la pared trasera
            front_dist = self.get_front_distance()

            self.get_logger().info(
                f'ENTER: dist_frontal={front_dist:.2f}m, '
                f'dist_recorrida={self.get_distance_traveled():.2f}m'
            )

            if front_dist > self.stop_distance:
                twist.linear.x = self.linear_speed * 0.7  # Velocidad reducida al entrar
            else:
                self.stop_robot()
                self.get_logger().info('¡Aparcamiento completado!')
                self.state = 'PARKED'
                return

        elif self.state == 'PARKED':
            # Robot aparcado, no hacer nada
            self.stop_robot()
            return

        self.cmd_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = AparcamientoNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Aparcamiento interrumpido.')
    finally:
        node.stop_robot()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

