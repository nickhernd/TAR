import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time
import math

class ControladorFiguras(Node):
    def __init__(self):
        super().__init__('movimiento_node')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        time.sleep(1) # Pequeña pausa para asegurar la conexión con Gazebo

    def publicar_velocidad(self, v_lineal, v_angular, duracion):
        """Función base para mandar velocidades durante un tiempo exacto"""
        msg = Twist()
        msg.linear.x = float(v_lineal)
        msg.angular.z = float(v_angular)
        
        fin = time.time() + duracion
        while time.time() < fin:
            self.publisher_.publish(msg)
            time.sleep(0.1) # Publicar a 10Hz
            
        # Parada de seguridad tras el movimiento
        msg.linear.x = 0.0
        msg.angular.z = 0.0
        self.publisher_.publish(msg)
        time.sleep(0.5) # Pausa entre cada lado para evitar inercias

    def hacer_cuadrado(self):
        self.get_logger().info("Trazando Cuadrado...")
        t_recto = 1.0 / 0.2  # Distancia 1m / vel 0.2m/s = 5s
        t_giro = (math.pi / 2) / 0.5 # 90 grados en radianes / vel 0.5rad/s = ~3.14s
        
        for _ in range(4):
            self.publicar_velocidad(0.2, 0.0, t_recto) # Avanzar
            self.publicar_velocidad(0.0, 0.5, t_giro)  # Girar 90 grados

    def hacer_triangulo(self):
        self.get_logger().info("Trazando Triangulo...")
        t_recto = 1.0 / 0.2
        # Para un triángulo equilátero, el robot gira el ángulo EXTERIOR (120 grados)
        t_giro = (2 * math.pi / 3) / 0.5 
        
        for _ in range(3):
            self.publicar_velocidad(0.2, 0.0, t_recto) # Avanzar
            self.publicar_velocidad(0.0, 0.5, t_giro)  # Girar 120 grados

    def hacer_infinito(self):
        self.get_logger().info("Trazando Infinito...")
        v_lin = 0.2
        v_ang = 0.4
        # Tiempo para dar una vuelta completa (360 grados = 2*pi rad)
        t_circulo = (2 * math.pi) / v_ang 
        
        # Círculo hacia la izquierda
        self.publicar_velocidad(v_lin, v_ang, t_circulo)
        # Círculo hacia la derecha
        self.publicar_velocidad(v_lin, -v_ang, t_circulo)

def main(args=None):
    rclpy.init(args=args)
    nodo = ControladorFiguras()
    
    print("\n--- CONTROL DE FIGURAS TURTLEBOT 3 ---")
    print("1. Cuadrado")
    print("2. Triángulo Equilátero")
    print("3. Infinito")
    print("--------------------------------------")
    opcion = input("Elige una figura (1, 2 o 3): ")
    
    if opcion == '1':
        nodo.hacer_cuadrado()
    elif opcion == '2':
        nodo.hacer_triangulo()
    elif opcion == '3':
        nodo.hacer_infinito()
    else:
        print("Opción no válida. Saliendo...")
        
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
