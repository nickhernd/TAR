import os
import launch
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Rutas de paquetes
    pkg_hospital_robot = get_package_share_directory('hospital_robot')
    pkg_hospital_world = get_package_share_directory('aws_robomaker_hospital_world')
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')

    # Configurar variables de entorno críticas
    models_path = os.path.join(pkg_hospital_world, 'models')
    fuel_models_path = os.path.join(pkg_hospital_world, 'fuel_models')
    
    set_gazebo_model_path = SetEnvironmentVariable(
        name='GAZEBO_MODEL_PATH',
        value=[models_path, ':', fuel_models_path, ':', os.environ.get('GAZEBO_MODEL_PATH', ''), ':/root/.gazebo/models']
    )

    set_gazebo_resource_path = SetEnvironmentVariable(
        name='GAZEBO_RESOURCE_PATH',
        value=['/usr/share/gazebo-11:', '/usr/share/gazebo_ros:', os.environ.get('GAZEBO_RESOURCE_PATH', '')]
    )

    # Archivo URDF
    urdf_file = os.path.join(pkg_hospital_robot, 'urdf', 'robot_hospitalario.urdf')
    with open(urdf_file, 'r') as infp:
        robot_description_config = infp.read()

    # Configuración de Gazebo
    world_path = os.path.join(pkg_hospital_world, 'worlds', 'hospital.world')
    
    # Declarar argumentos
    gui_arg = DeclareLaunchArgument('gui', default_value='true')
    patrol_arg = DeclareLaunchArgument('patrol', default_value='false')

    # Incluir servidor de Gazebo
    gzserver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'world': world_path, 'verbose': 'true'}.items()
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
        parameters=[{'robot_description': robot_description_config, 'use_sim_time': True}]
    )

    # Nodo Joint State Publisher
    joint_state_publisher = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        parameters=[{'use_sim_time': True}]
    )

    # Nodo para spawnear el robot en Gazebo (Zona recepción despejada)
    spawn_entity = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', 'robot_description', '-entity', 'hospital_bot', '-x', '-3.0', '-y', '0.0', '-z', '0.2'],
        output='screen'
    )

    # Nodo RViz2
    rviz_config_file = os.path.join(pkg_hospital_robot, 'config', 'robot_view.rviz')
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_file],
        parameters=[{'use_sim_time': True}]
    )

    # Nodo de patrulla (opcional)
    patrol_node = Node(
        package='hospital_robot',
        executable='patrol.py',
        name='hospital_patrol',
        condition=launch.conditions.IfCondition(LaunchConfiguration('patrol')),
        parameters=[{'use_sim_time': True}]
    )

    return LaunchDescription([
        set_gazebo_model_path,
        set_gazebo_resource_path,
        gui_arg,
        patrol_arg,
        gzserver,
        gzclient,
        robot_state_publisher,
        joint_state_publisher,
        spawn_entity,
        rviz_node,
        patrol_node
    ])
