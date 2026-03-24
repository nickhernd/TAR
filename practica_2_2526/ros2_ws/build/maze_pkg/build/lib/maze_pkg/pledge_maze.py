import math
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

class PledgeFinal(Node):
    def __init__(self):
        super().__init__('pledge_final')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.create_subscription(LaserScan, '/scan', self.scan_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)

        # Estados: 'NORTE' (ir recto), 'MURO' (seguir pared)
        self.state = 'NORTE'
        self.init_yaw = None
        self.curr_yaw = 0.0
        
        # --- Lógica de Contador de Cuadrantes ---
        self.contador = 0
        self.last_q = 0 # Cuadrante anterior
        
        self.get_logger().info('Iniciando Autómata Pledge Robusto...')

    def odom_cb(self, msg):
        # Extraer Yaw
        q = msg.pose.pose.orientation
        self.curr_yaw = math.atan2(2.0*(q.w*q.z + q.x*q.y), 1.0-2.0*(q.y*q.y + q.z*q.z))
        
        if self.init_yaw is None:
            self.init_yaw = self.curr_yaw
            return

        # Calcular cuadrante actual (-2, -1, 0, 1, 2)
        diff = self.normalize_angle(self.curr_yaw - self.init_yaw)
        current_q = int(round(diff / (math.pi / 2)))

        # Solo actualizar si el cambio es real (evitar saltos espurios)
        if current_q != self.last_q:
            step = current_q - self.last_q
            if step > 2: step -= 4
            if step < -2: step += 4
            
            self.contador += step
            self.last_q = current_q
            self.get_logger().info(f'GIRO DETECTADO. Contador: {self.contador}')

    def get_dist_at_angle(self, msg, target_deg):
        """Busca el valor del láser en un ángulo específico usando trigonometría"""
        target_rad = math.radians(target_deg)
        min_val = 10.0
        # Radio de seguridad para no leer el propio chasis
        for i, dist in enumerate(msg.ranges):
            if dist < 0.18 or math.isinf(dist) or math.isnan(dist):
                continue
            
            angle = msg.angle_min + i * msg.angle_increment
            if abs(self.normalize_angle(angle - target_rad)) < math.radians(15):
                if dist < min_val:
                    min_val = dist
        return min_val

    def scan_cb(self, msg):
        if self.init_yaw is None: return
        
        # 1. Lecturas de seguridad
        dist_frontal = self.get_dist_at_angle(msg, 0)
        dist_izq = self.get_dist_at_angle(msg, 90)

        cmd = Twist()

        # 2. Máquina de Estados
        if self.state == 'NORTE':
            if dist_frontal < 0.45:
                self.state = 'MURO'
                self.get_logger().info('¡Muro! Siguiendo pared izquierda.')
            else:
                # PID de rumbo
                err = self.normalize_angle(self.init_yaw - self.curr_yaw)
                cmd.linear.x = 0.15
                cmd.angular.z = 0.8 * err

        elif self.state == 'MURO':
            # Condición de escape Pledge: Contador 0 y Norte despejado
            dist_norte = abs(self.normalize_angle(self.curr_yaw - self.init_yaw))
            
            if self.contador == 0 and dist_norte < 0.15 and dist_frontal > 0.6:
                self.state = 'NORTE'
                self.get_logger().info('Contador a cero. Escapando...')
                return

            # Navegación
            if dist_frontal < 0.35:
                # Esquina de frente: Rotar derecha (resta al contador)
                cmd.linear.x = 0.0
                cmd.angular.z = -0.5
            elif dist_izq > 0.6:
                # Esquina exterior: Girar izquierda (suma al contador)
                cmd.linear.x = 0.1
                cmd.angular.z = 0.4
            else:
                # Mantenerse paralelo a la pared
                cmd.linear.x = 0.12
                cmd.angular.z = 1.3 * (dist_izq - 0.35)

        self.pub.publish(cmd)

    def normalize_angle(self, angle):
        while angle > math.pi: angle -= 2.0 * math.pi
        while angle < -math.pi: angle += 2.0 * math.pi
        return angle

def main():
    rclpy.init()
    node = PledgeFinal()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()