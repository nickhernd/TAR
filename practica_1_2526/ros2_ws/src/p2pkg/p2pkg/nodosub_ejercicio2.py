import rclpy
from rclpy.node import Node
from interfaz.msg import P2pkgMensaje

class NodoSub(Node):

    def __init__(self):
        super().__init__('nodosub_ejercicio2')
        self.subscription = self.create_subscription(
            P2pkgMensaje,
            '/topic_ejercicio2',
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        self.get_logger().info(
            f"Fecha={msg.fecha} | numero={msg.numero} | "
            f"pos.x={msg.posicion.position.x:.3f} | orient.w={msg.posicion.orientation.w:.3f}")

def main(args=None):
    rclpy.init(args=args)
    nodo = NodoSub()
    rclpy.spin(nodo)
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
