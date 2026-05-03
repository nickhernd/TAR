import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class HospitalPatrol(Node):
    def __init__(self):
        super().__init__('hospital_patrol')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.start_time = time.time()
        self.get_logger().info('Iniciando patrulla del hospital...')

    def timer_callback(self):
        msg = Twist()
        elapsed = time.time() - self.start_time
        
        # Ciclo de movimiento simple: avanzar 5s, girar 2s
        cycle = elapsed % 7.0
        if cycle < 5.0:
            msg.linear.x = 0.3  # Avanzar
            msg.angular.z = 0.0
        else:
            msg.linear.x = 0.0
            msg.angular.z = 0.5  # Girar
            
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    patrol = HospitalPatrol()
    rclpy.spin(patrol)
    patrol.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
