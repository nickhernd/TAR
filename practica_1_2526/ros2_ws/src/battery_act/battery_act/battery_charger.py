import time
import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node
from interfaz.action import BatteryAction

class BatteryCharger(Node):

    def __init__(self):
        super().__init__('battery_charger')
        self._action_server = ActionServer(
            self,
            BatteryAction,
            'battery_action',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback)
        self.get_logger().info('Servidor de batería listo.')

    def goal_callback(self, goal_request):
        self.get_logger().info(f'Goal recibido: aviso al {goal_request.target_percentage}%')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        self.get_logger().info('Cancelación recibida.')
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        self.get_logger().info('Iniciando descarga de batería...')
        feedback_msg = BatteryAction.Feedback()
        current_battery = 100

        while current_battery > goal_handle.request.target_percentage:
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('Acción cancelada.')
                return BatteryAction.Result()

            feedback_msg.current_percentage = current_battery
            self.get_logger().info(f'Batería actual: {current_battery}%')
            goal_handle.publish_feedback(feedback_msg)
            current_battery -= 5
            time.sleep(1)

        goal_handle.succeed()
        result = BatteryAction.Result()
        result.warning = '¡Batería baja, por favor cargue el robot!'
        self.get_logger().info(result.warning)
        return result

def main(args=None):
    rclpy.init(args=args)
    server = BatteryCharger()
    rclpy.spin(server)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
