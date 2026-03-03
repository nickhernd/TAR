import rclpy
from rclpy.node import Node
from interfaz_temp.srv import TempConversion

class TempServer(Node):

    def __init__(self):
        super().__init__('temp_server')
        self.srv = self.create_service(TempConversion, 'temp_conversion', self.callback)
        self.get_logger().info('Servidor de conversión de temperatura listo.')

    def callback(self, request, response):
        if request.conversion_type == 'Cel_to_Far':
            response.converted_temp = (request.input_temp * 9/5) + 32
            self.get_logger().info(f'{request.input_temp}°C -> {response.converted_temp}°F')
        elif request.conversion_type == 'Far_to_Cel':
            response.converted_temp = (request.input_temp - 32) * 5/9
            self.get_logger().info(f'{request.input_temp}°F -> {response.converted_temp}°C')
        else:
            self.get_logger().error(f'Tipo de conversión desconocido: {request.conversion_type}')
            response.converted_temp = 0.0
        return response

def main(args=None):
    rclpy.init(args=args)
    server = TempServer()
    rclpy.spin(server)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
