import rclpy
from rclpy.node import Node
from interfaz.msg import P2pkgMensaje
from geometry_msgs.msg import Pose
from random import random
from datetime import date

class NodoPub(Node):

    def __init__(self):
        super().__init__('nodopub_ejercicio2')
        self.declare_parameter('numero', 5)
        self.publisher_ = self.create_publisher(P2pkgMensaje, '/topic_ejercicio2', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        msg = P2pkgMensaje()
        msg.numero = self.get_parameter('numero').get_parameter_value().integer_value
        msg.fecha = str(date.today())
        msg.posicion = Pose()
        msg.posicion.position.x = random()
        msg.posicion.position.y = random()
        msg.posicion.position.z = random()
        msg.posicion.orientation.x = random()
        msg.posicion.orientation.y = random()
        msg.posicion.orientation.z = random()
        msg.posicion.orientation.w = random()
        self.publisher_.publish(msg)
        self.get_logger().info(
            f"Fecha={msg.fecha} | numero={msg.numero} | "
            f"pos.x={msg.posicion.position.x:.3f} | orient.w={msg.posicion.orientation.w:.3f}")

def main(args=None):
    rclpy.init(args=args)
    nodo = NodoPub()
    rclpy.spin(nodo)
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
