import os
import launch
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Rutas de paquetes
    pkg_hospital_robot = get_package_share_directory('hospital_robot')
    pkg_hospital_world = get_package_share_directory('aws_robomaker_hospital_world')
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')

    # Archivo URDF
    urdf_file = os.path.join(pkg_hospital_robot, 'urdf', 'robot_v2.urdf')
    with open(urdf_file, 'r') as infp:
        robot_description_config = infp.read()

    # Configuración de Gazebo
    world_path = os.path.join(pkg_hospital_world, 'worlds', 'hospital.world')
    
    # Declarar argumentos
    gui_arg = DeclareLaunchArgument('gui', default_value='true')

    # Incluir servidor de Gazebo
    gzserver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'world': world_path}.items()
    )

    # Incluir cliente de Gazebo (GUI)
    gzclient = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzclient.launch.py')
        ),
        condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    # Nodo Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description_config}]
    )

    # Nodo para spawnear el robot en Gazebo
    spawn_entity = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', 'robot_description', '-entity', 'hospital_robot', '-x', '0', '-y', '0', '-z', '0.5'],
        output='screen'
    )

    return LaunchDescription([
        gui_arg,
        gzserver,
        gzclient,
        robot_state_publisher,
        spawn_entity
    ])
