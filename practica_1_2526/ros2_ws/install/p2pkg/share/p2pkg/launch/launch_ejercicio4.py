#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace

def generate_launch_description():
    numero_arg = DeclareLaunchArgument(
        'numero',
        default_value='7',
        description='Valor del campo numero del mensaje'
    )

    group = GroupAction([
        PushRosNamespace('miGrupo'),
        Node(
            package='p2pkg',
            executable='nodopub_ejercicio2',
            name='nodopub_ejercicio2',
            parameters=[{'numero': LaunchConfiguration('numero')}],
            remappings=[('/topic_ejercicio2', '/miGrupo/topic_ejercicio2')]
        ),
        Node(
            package='p2pkg',
            executable='nodosub_ejercicio2',
            name='nodosub_ejercicio2',
            remappings=[('/topic_ejercicio2', '/miGrupo/topic_ejercicio2')]
        )
    ])

    return LaunchDescription([
        numero_arg,
        group,
    ])
