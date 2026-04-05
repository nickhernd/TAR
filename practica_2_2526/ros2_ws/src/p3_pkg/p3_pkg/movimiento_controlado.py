#!/usr/bin/env python3
"""
Nodo de movimiento con controlador PID para corregir errores de odometría.
Ejercicio 4 - Parte 1: Corrección de trayectorias.

Uso:
    ros2 run p3_pkg movimiento_controlado --ros-args -p movimiento:=0
    Donde movimiento: 0=lineal, 1=triángulo, 2=cuadrado, 3=infinito
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import math


class MovimientoControladoNode(Node):
    def __init__(self):
        super().__init__('movimiento_controlado')

        # Parámetro de movimiento
        self.declare_parameter('movimiento', 0)
        self.mov_type = self.get_parameter('movimiento').value

        # Publisher y subscriber
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.odom_sub = self.create_subscription(Odometry, '/odom', self.odom_callback, 10)

        # Odometría
        self.x = 0.0
        self.y = 0.0
        self.yaw = 0.0
        self.odom_received = False

        # =============================================
        # GANANCIAS DEL CONTROLADOR
        # =============================================
        self.Kp_angular = 2.0
        self.Ki_angular = 0.01
        self.Kd_angular = 0.1
        self.Kp_heading = 1.5

        # Velocidades
        self.max_linear = 0.2
        self.max_angular = 0.5
        self.min_angular = 0.05

        # Tolerancias
        self.distance_tolerance = 0.02
        self.angle_tolerance = 0.02

        # Variables PID
        self.integral_error = 0.0
        self.prev_error = 0.0

        # Máquina de estados
        self.action = 'WAIT_ODOM'
        self.steps = []
        self.step_index = 0

        # Referencias para el paso actual
        self.start_x = 0.0
        self.start_y = 0.0
        self.target_yaw = 0.0
        self.target_distance = 0.0

        # Timer principal a 20 Hz
        self.timer = self.create_timer(0.05, self.control_loop)

        self.get_logger().info(f'Movimiento controlado iniciado. Tipo: {self.mov_type}')

    def odom_callback(self, msg):
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        self.yaw = math.atan2(siny_cosp, cosy_cosp)
        self.odom_received = True

    def normalize_angle(self, angle):
        while angle > math.pi:
            angle -= 2.0 * math.pi
        while angle < -math.pi:
            angle += 2.0 * math.pi
        return angle

    def stop_robot(self):
        twist = Twist()
        self.cmd_pub.publish(twist)

    def build_steps(self):
        """Construye la lista de pasos según el tipo de movimiento."""
        if self.mov_type == 0:
            return [('advance', 2.0)]

        elif self.mov_type == 1:
            # Triángulo equilátero de lado 3m
            steps = []
            for _ in range(3):
                steps.append(('advance', 3.0))
                steps.append(('turn', math.radians(120)))
            return steps

        elif self.mov_type == 2:
            # Cuadrado de lado 1m
            steps = []
            for _ in range(4):
                steps.append(('advance', 1.0))
                steps.append(('turn', math.radians(90)))
            return steps

        elif self.mov_type == 3:
            # Infinito (pajarita): dos diagonales cruzadas
            angle = math.radians(120)  # Giro exterior de 120°
            steps = []
            # 1. Subir 0.5m
            steps.append(('advance', 0.5))
            # 2. Girar -120° (derecha)
            steps.append(('turn', -angle))
            # 3. Diagonal 1.0m (cruza el centro)
            steps.append(('advance', 1.0))
            # 4. Girar +120° (izquierda)
            steps.append(('turn', angle))
            # 5. Subir 0.5m
            steps.append(('advance', 0.5))
            # 6. Girar +120° (izquierda)
            steps.append(('turn', angle))
            # 7. Diagonal 1.0m (vuelve al centro)
            steps.append(('advance', 1.0))
            # 8. Girar -120° (derecha, recuperar orientación)
            steps.append(('turn', -angle))
            return steps

        return []

    def start_next_step(self):
        """Inicia el siguiente paso de la secuencia."""
        if self.step_index >= len(self.steps):
            self.action = 'DONE'
            self.stop_robot()
            self.timer.cancel()
            self.get_logger().info('=== Movimiento completado ===')
            self.get_logger().info(
                f'Posición final: x={self.x:.3f}, y={self.y:.3f}, '
                f'yaw={math.degrees(self.yaw):.1f}°'
            )
            return

        step_type, value = self.steps[self.step_index]

        if step_type == 'advance':
            self.action = 'ADVANCE'
            self.start_x = self.x
            self.start_y = self.y
            self.target_distance = value
            self.target_yaw = self.yaw
            self.get_logger().info(
                f'[Paso {self.step_index + 1}/{len(self.steps)}] '
                f'Avanzar {value:.2f}m'
            )

        elif step_type == 'turn':
            self.action = 'TURN'
            self.target_yaw = self.normalize_angle(self.yaw + value)
            self.integral_error = 0.0
            self.prev_error = 0.0
            self.get_logger().info(
                f'[Paso {self.step_index + 1}/{len(self.steps)}] '
                f'Girar {math.degrees(value):.1f}°'
            )

    def control_loop(self):
        twist = Twist()

        # ---- ESPERAR ODOMETRÍA ----
        if self.action == 'WAIT_ODOM':
            if not self.odom_received:
                return
            self.get_logger().info(
                f'Odometría OK. Posición inicial: '
                f'x={self.x:.3f}, y={self.y:.3f}, yaw={math.degrees(self.yaw):.1f}°'
            )
            self.steps = self.build_steps()
            self.step_index = 0
            self.start_next_step()
            return

        # ---- AVANCE CON CORRECCIÓN DE RUMBO ----
        elif self.action == 'ADVANCE':
            dx = self.x - self.start_x
            dy = self.y - self.start_y
            traveled = math.sqrt(dx * dx + dy * dy)
            remaining = self.target_distance - traveled

            if remaining <= self.distance_tolerance:
                self.stop_robot()
                self.step_index += 1
                self.start_next_step()
                return

            # Velocidad lineal proporcional a distancia restante
            linear_vel = min(self.max_linear, max(0.05, remaining * 1.0))

            # Corrección de rumbo
            heading_error = self.normalize_angle(self.target_yaw - self.yaw)
            angular_vel = self.Kp_heading * heading_error
            angular_vel = max(-self.max_angular, min(self.max_angular, angular_vel))

            twist.linear.x = linear_vel
            twist.angular.z = angular_vel

        # ---- GIRO CON PID ----
        elif self.action == 'TURN':
            error = self.normalize_angle(self.target_yaw - self.yaw)

            if abs(error) <= self.angle_tolerance:
                self.stop_robot()
                self.step_index += 1
                self.start_next_step()
                return

            dt = 0.05

            # PID
            self.integral_error += error * dt
            self.integral_error = max(-1.0, min(1.0, self.integral_error))
            derivative = (error - self.prev_error) / dt
            self.prev_error = error

            angular_vel = (self.Kp_angular * error +
                          self.Ki_angular * self.integral_error +
                          self.Kd_angular * derivative)

            angular_vel = max(-self.max_angular, min(self.max_angular, angular_vel))

            if abs(angular_vel) < self.min_angular and abs(error) > self.angle_tolerance:
                angular_vel = self.min_angular if angular_vel > 0 else -self.min_angular

            twist.angular.z = angular_vel

        # ---- COMPLETADO ----
        elif self.action == 'DONE':
            self.stop_robot()
            return

        self.cmd_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = MovimientoControladoNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Interrumpido.')
    finally:
        node.stop_robot()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
