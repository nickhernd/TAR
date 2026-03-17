#!/usr/bin/env python3
"""
res_maze.py - Maze solver for Turtlebot3 using LiDAR (left-wall following)

Algorithm:
  - If no wall on the left  -> turn left (follow the wall)
  - If wall ahead            -> turn right
  - Otherwise               -> go straight
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist


# Tunable parameters
LINEAR_SPEED   = 0.15   # m/s
ANGULAR_SPEED  = 0.5    # rad/s
WALL_DIST      = 0.35   # metres: desired distance to left wall
FRONT_DIST     = 0.40   # metres: obstacle threshold ahead


class MazeSolver(Node):

    def __init__(self):
        super().__init__('maze_solver')

        self.pub_cmd = self.create_publisher(Twist, '/cmd_vel', 10)
        self.sub_scan = self.create_subscription(
            LaserScan, '/scan', self.scan_callback, 10)

        self.get_logger().info('MazeSolver node started (left-wall following)')

    # ------------------------------------------------------------------
    def scan_callback(self, msg: LaserScan):
        """
        LaserScan for Turtlebot3 Waffle/Burger:
          - 360 rays, index 0 = forward, increasing counter-clockwise
          - index 90  ≈ left
          - index 180 ≈ rear
          - index 270 ≈ right
        """
        ranges = msg.ranges
        n = len(ranges)

        def safe(i):
            """Return range, replacing inf/nan with a large value."""
            v = ranges[i % n]
            if v == float('inf') or v != v:
                return 10.0
            return v

        # Sector distances (min over a small window to be robust to noise)
        front = min(safe(i) for i in range(-10, 11))          # ±10° ahead
        left  = min(safe(i) for i in range(80, 101))          # ~90° left
        front_left = min(safe(i) for i in range(40, 61))      # ~50° left-front

        cmd = Twist()

        if front < FRONT_DIST:
            # Obstacle ahead -> turn right in place
            cmd.linear.x  = 0.0
            cmd.angular.z = -ANGULAR_SPEED
            self.get_logger().debug(f'TURN RIGHT  | front={front:.2f}')

        elif left > WALL_DIST + 0.1:
            # No wall on the left -> turn left to find/follow it
            cmd.linear.x  = LINEAR_SPEED * 0.7
            cmd.angular.z = ANGULAR_SPEED * 0.6
            self.get_logger().debug(f'TURN LEFT   | left={left:.2f}')

        elif left < WALL_DIST - 0.1:
            # Too close to the left wall -> turn slightly right
            cmd.linear.x  = LINEAR_SPEED
            cmd.angular.z = -ANGULAR_SPEED * 0.3
            self.get_logger().debug(f'CORRECT R   | left={left:.2f}')

        elif front_left < FRONT_DIST:
            # Corner approaching on the left -> turn right a bit
            cmd.linear.x  = LINEAR_SPEED
            cmd.angular.z = -ANGULAR_SPEED * 0.4
            self.get_logger().debug(f'CORNER      | front_left={front_left:.2f}')

        else:
            # Clear path, wall on the left at good distance -> go straight
            cmd.linear.x  = LINEAR_SPEED
            cmd.angular.z = 0.0
            self.get_logger().debug(f'STRAIGHT    | left={left:.2f} front={front:.2f}')

        self.pub_cmd.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = MazeSolver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.pub_cmd.publish(Twist())   # stop the robot
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
