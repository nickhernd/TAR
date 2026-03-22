#!/usr/bin/env python3
"""
res_maze.py - Maze solver para Turtlebot3 con LiDAR (left-wall following)

Estados:
  FIND_WALL  -> avanza recto hasta encontrar una pared al frente
  TURN_RIGHT -> gira derecha hasta que el frente quede libre
  FORWARD    -> sigue la pared izquierda con control proporcional
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

LINEAR_SPEED   = 0.12
ANGULAR_SPEED  = 0.40
WALL_DIST      = 0.35
FRONT_THRESH   = 0.45
KP             = 0.8
MIN_TURN_TICKS = 15


class MazeSolver(Node):

    def __init__(self):
        super().__init__('maze_solver')
        self.pub_cmd = self.create_publisher(Twist, '/cmd_vel', 10)
        self.sub_scan = self.create_subscription(
            LaserScan, '/scan', self.scan_callback, 10)
        self.state = 'FIND_WALL'
        self.turn_ticks = 0
        self.get_logger().info('MazeSolver iniciado — estado: FIND_WALL')

    def scan_callback(self, msg: LaserScan):
        ranges = msg.ranges
        n = len(ranges)

        def safe(i):
            v = ranges[i % n]
            return 10.0 if (v == float('inf') or v != v or v == 0.0) else v

        front = min(safe(i) for i in range(-20, 21))
        left  = min(safe(i) for i in range(75, 106))

        cmd = Twist()

        if self.state == 'FIND_WALL':
            if front < FRONT_THRESH:
                # Encontramos pared al frente -> empezar a girar derecha
                self.state = 'TURN_RIGHT'
                self.turn_ticks = 0
                self.get_logger().info('-> TURN_RIGHT')
            else:
                # Avanzar recto hasta encontrar pared
                cmd.linear.x  = LINEAR_SPEED
                cmd.angular.z = 0.0

        elif self.state == 'TURN_RIGHT':
            cmd.linear.x  = 0.0
            cmd.angular.z = -ANGULAR_SPEED
            self.turn_ticks += 1
            if self.turn_ticks >= MIN_TURN_TICKS and front > FRONT_THRESH + 0.15:
                self.state = 'FORWARD'
                self.get_logger().info('-> FORWARD')

        else:  # FORWARD
            if front < FRONT_THRESH:
                self.state = 'TURN_RIGHT'
                self.turn_ticks = 0
                self.get_logger().info(f'-> TURN_RIGHT | front={front:.2f}')
            else:
                # error > 0: left muy lejos -> gira izquierda
                # error < 0: left muy cerca -> gira derecha
                error = left - WALL_DIST
                correction = max(-ANGULAR_SPEED, min(ANGULAR_SPEED, KP * error))
                cmd.linear.x  = LINEAR_SPEED
                cmd.angular.z = correction

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
