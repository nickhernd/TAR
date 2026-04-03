import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import matplotlib.pyplot as plt

class Dibujante(Node):
    def __init__(self):
        super().__init__('dibuja_mov_node')
        self.subscription = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10)
        self.x_data = []
        self.y_data = []
        self.get_logger().info("Escuchando /odom. Mueve el robot. Pulsa Ctrl+C para ver la grafica.")

    def odom_callback(self, msg):
        # Guardar las coordenadas X e Y
        self.x_data.append(msg.pose.pose.position.x)
        self.y_data.append(msg.pose.pose.position.y)

def main(args=None):
    rclpy.init(args=args)
    nodo = Dibujante()
    
    try:
        rclpy.spin(nodo)
    except KeyboardInterrupt:
        pass
    finally:
        # Cuando pulsamos Ctrl+C, dibujar la gráfica
        plt.figure(figsize=(8,8))
        plt.plot(nodo.x_data, nodo.y_data, '-b', label='Trayectoria')
        plt.plot(nodo.x_data[0], nodo.y_data[0], 'go', label='Inicio') # Punto verde de inicio
        plt.plot(nodo.x_data[-1], nodo.y_data[-1], 'ro', label='Fin')  # Punto rojo de fin
        plt.title('Trayectoria del Turtlebot 3 (Odometria)')
        plt.xlabel('X (metros)')
        plt.ylabel('Y (metros)')
        plt.grid(True)
        plt.axis('equal') # Para que los cuadrados se vean cuadrados y no rectangulos
        plt.legend()
        plt.show()
        
        nodo.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
