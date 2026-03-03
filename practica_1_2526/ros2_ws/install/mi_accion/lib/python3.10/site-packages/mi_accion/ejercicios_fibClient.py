import sys
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from std_msgs.msg import String
from interfaz.action import EjFibonacci

class EjFibonacciClient(Node):

    def __init__(self):
        super().__init__('ejfibonacci_action_client')
        self._action_client = ActionClient(self, EjFibonacci, 'ejfibonacci')
        self._publisher = self.create_publisher(String, '/estado_accion', 10)
        self._in_progress = False
        self._timer = self.create_timer(1.0, self.publish_estado)

    def publish_estado(self):
        if self._in_progress:
            msg = String()
            msg.data = 'en proceso'
            self._publisher.publish(msg)
            self.get_logger().info('Publicando: en proceso')

    def send_goal(self, orden):
        goal_msg = EjFibonacci.Goal()
        goal_msg.orden = orden
        self._action_client.wait_for_server()
        self._in_progress = True
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            self._in_progress = False
            return
        self.get_logger().info('Goal accepted :)')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        self._in_progress = False
        result = future.result().result
        self.get_logger().info('Resultado: {0}'.format(result.secuencia_final))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Feedback (sqrt media): {:.4f}'.format(feedback.feedback_value))

def main(args=None):
    rclpy.init(args=args)
    client = EjFibonacciClient()

    if len(sys.argv) > 1:
        orden = int(sys.argv[1])
    else:
        orden = 10

    client.send_goal(orden)
    rclpy.spin(client)

if __name__ == '__main__':
    main()
