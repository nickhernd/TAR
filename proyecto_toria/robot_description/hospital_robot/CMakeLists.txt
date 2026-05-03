cmake_minimum_required(VERSION 3.8)
project(hospital_robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)

install(DIRECTORY launch urdf meshes worlds config
  DESTINATION share/${PROJECT_NAME}
)

install(PROGRAMS
  scripts/patrol.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
