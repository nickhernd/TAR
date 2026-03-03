import sys
import rclpy
from rclpy.node import Node
from interfaz_temp.srv import TempConversion

class TempClient(Node):

    def __init__(self):
        super().__init__('temp_client')
        self.cli = self.create_client(TempConversion, 'temp_conversion')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Esperando servidor...')
        self.req = TempConversion.Request()

    def send_request(self, temp, conversion_type):
        self.req.input_temp = temp
        self.req.conversion_type = conversion_type
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        return future.result()

def main(args=None):
    rclpy.init(args=args)
    client = TempClient()

    if len(sys.argv) < 3:
        print('Uso: ros2 run service_temp client <temperatura> <Cel_to_Far|Far_to_Cel>')
        return

    temp = float(sys.argv[1])
    conversion_type = sys.argv[2]

    response = client.send_request(temp, conversion_type)
    client.get_logger().info(f'Resultado: {response.converted_temp:.2f}')
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
