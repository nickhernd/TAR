#!/usr/bin/env python3
"""
res_maze.py - Maze solver para Turtlebot3 con LiDAR (left-wall following)

Dos estados:
  FORWARD    -> control proporcional siguiendo pared izquierda
                (si left es grande -> gira izquierda para buscarla)
                (si left es pequeño -> gira derecha para separarse)
  TURN_RIGHT -> gira derecha en sitio hasta que el frente quede libre
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

# --- Parámetros ---
LINEAR_SPEED  = 0.12   # m/s
ANGULAR_SPEED = 0.40   # rad/s
WALL_DIST     = 0.40   # m distancia deseada a pared izquierda
FRONT_THRESH  = 0.45   # m umbral obstáculo al frente
KP            = 0.8    # ganancia proporcional
MIN_TURN_TICKS = 15    # mínimo de callbacks girando antes de poder salir


class MazeSolver(Node):

    def __init__(self):
        super().__init__('maze_solver')
        self.pub_cmd = self.create_publisher(Twist, '/cmd_vel', 10)
        self.sub_scan = self.create_subscription(
            LaserScan, '/scan', self.scan_callback, 10)
        self.state = 'FORWARD'
        self.turn_ticks = 0
        self.get_logger().info('MazeSolver iniciado')

    def scan_callback(self, msg: LaserScan):
        ranges = msg.ranges
        n = len(ranges)

        def safe(i):
            v = ranges[i % n]
            return 10.0 if (v == float('inf') or v != v or v == 0.0) else v

        front = min(safe(i) for i in range(-20, 21))   # ±20° frente
        left  = min(safe(i) for i in range(75, 106))   # ~90° izquierda

        cmd = Twist()

        if self.state == 'FORWARD':
            if front < FRONT_THRESH:
                self.state = 'TURN_RIGHT'
                self.turn_ticks = 0
                self.get_logger().info(f'-> TURN_RIGHT | front={front:.2f}')
            else:
                # Control proporcional:
                # left > WALL_DIST  =>  error > 0  =>  gira izquierda (+z) para acercarse
                # left < WALL_DIST  =>  error < 0  =>  gira derecha (-z) para alejarse
                error = left - WALL_DIST
                correction = KP * error
                correction = max(-ANGULAR_SPEED, min(ANGULAR_SPEED, correction))
                cmd.linear.x  = LINEAR_SPEED
                cmd.angular.z = correction

        else:  # TURN_RIGHT
            cmd.linear.x  = 0.0
            cmd.angular.z = -ANGULAR_SPEED
            self.turn_ticks += 1
            if self.turn_ticks >= MIN_TURN_TICKS and front > FRONT_THRESH + 0.15:
                self.state = 'FORWARD'
                self.get_logger().info('-> FORWARD')

        self.pub_cmd.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = MazeSolver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.pub_cmd.publish(Twist())
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
