import sys
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from interfaz.action import BatteryAction

class BatteryClient(Node):

    def __init__(self):
        super().__init__('battery_client')
        self._action_client = ActionClient(self, BatteryAction, 'battery_action')

    def send_goal(self, target_percentage):
        goal_msg = BatteryAction.Goal()
        goal_msg.target_percentage = target_percentage
        self._action_client.wait_for_server()
        self.get_logger().info(f'Enviando goal: aviso al {target_percentage}%')
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rechazado.')
            return
        self.get_logger().info('Goal aceptado.')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Resultado: {result.warning}')
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Feedback - Batería actual: {feedback.current_percentage}%')

def main(args=None):
    rclpy.init(args=args)
    client = BatteryClient()

    if len(sys.argv) > 1:
        target = int(sys.argv[1])
    else:
        target = 20

    client.send_goal(target)
    rclpy.spin(client)

if __name__ == '__main__':
    main()
