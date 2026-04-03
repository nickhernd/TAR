import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time
import math
import sys

class ControladorFiguras(Node):
    def __init__(self):
        super().__init__('movimiento_node')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        time.sleep(1) # Pausa para conectar con Gazebo

    def publicar_velocidad(self, v_lineal, v_angular, duracion):
        msg = Twist()
        msg.linear.x = float(v_lineal)
        msg.angular.z = float(v_angular)
        
        fin = time.time() + duracion
        while time.time() < fin:
            self.publisher_.publish(msg)
            time.sleep(0.1)
            
        msg.linear.x = 0.0
        msg.angular.z = 0.0
        self.publisher_.publish(msg)
        time.sleep(0.5)

    def hacer_linea(self):
        self.get_logger().info("Opción 0: Avanzando 2 metros...")
        t_recto = 2.0 / 0.2  # 2 metros / 0.2 m/s = 10 s
        self.publicar_velocidad(0.2, 0.0, t_recto)

    def hacer_triangulo(self):
        self.get_logger().info("Opción 1: Triángulo de 3 metros...")
        t_recto = 3.0 / 0.2  # 3 metros
        t_giro = (2 * math.pi / 3) / 0.5  # Giro exterior de 120 grados
        
        for _ in range(3):
            self.publicar_velocidad(0.2, 0.0, t_recto)
            self.publicar_velocidad(0.0, 0.5, t_giro)

    def hacer_cuadrado(self):
        self.get_logger().info("Opción 2: Cuadrado de 1 metro...")
        t_recto = 1.0 / 0.2  # 1 metro
        t_giro = (math.pi / 2) / 0.5 # 90 grados
        
        for _ in range(4):
            self.publicar_velocidad(0.2, 0.0, t_recto)
            self.publicar_velocidad(0.0, 0.5, t_giro)

    def hacer_infinito(self):
        self.get_logger().info("Opción 3: Infinito poligonal (lazo)...")
        
        # Calculo de tiempos teoricos
        t_recto_corto = 0.5 / 0.2        # Lados verticales: 0.5m a 0.2m/s = 2.5s
        t_recto_largo = 1.0 / 0.2        # Diagonales: 1.0m a 0.2m/s = 5.0s
        t_giro = (2 * math.pi / 3) / 0.5 # Giro exterior de 120 grados (2*pi/3) = ~4.18s
        
        # 1. Avanzar 0.5m (Lado izquierdo, hacia arriba)
        self.publicar_velocidad(0.2, 0.0, t_recto_corto)
        
        # 2. Girar 120 grados a la DERECHA (para apuntar hacia abajo-derecha)
        self.publicar_velocidad(0.0, -0.5, t_giro)
        
        # 3. Avanzar 1.0m (Diagonal cruzando el centro)
        self.publicar_velocidad(0.2, 0.0, t_recto_largo)
        
        # 4. Girar 120 grados a la IZQUIERDA (para volver a mirar hacia el norte)
        self.publicar_velocidad(0.0, 0.5, t_giro)
        
        # 5. Avanzar 0.5m (Lado derecho, hacia arriba)
        self.publicar_velocidad(0.2, 0.0, t_recto_corto)
        
        # 6. Girar 120 grados a la IZQUIERDA (para apuntar hacia abajo-izquierda)
        self.publicar_velocidad(0.0, 0.5, t_giro)
        
        # 7. Avanzar 1.0m (Diagonal de vuelta al origen)
        self.publicar_velocidad(0.2, 0.0, t_recto_largo)
        
        # 8. Girar 120 grados a la DERECHA (para recuperar la orientación original)
        self.publicar_velocidad(0.0, -0.5, t_giro)
def main(args=None):
    rclpy.init(args=args)
    nodo = ControladorFiguras()
    
    # Comprobar qué argumento se ha pasado por terminal
    # sys.argv[0] es el nombre del script, sys.argv[1] es el argumento (0, 1, 2, 3)
    # Ignoramos argumentos extra que mete ROS 2 como --ros-args
    opcion = None
    for arg in sys.argv[1:]:
        if arg in ['0', '1', '2', '3']:
            opcion = arg
            break

    if opcion == '0':
        nodo.hacer_linea()
    elif opcion == '1':
        nodo.hacer_triangulo()
    elif opcion == '2':
        nodo.hacer_cuadrado()
    elif opcion == '3':
        nodo.hacer_infinito()
    else:
        nodo.get_logger().error("Debes pasar 0, 1, 2 o 3 por linea de comandos.")
        
    nodo.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
