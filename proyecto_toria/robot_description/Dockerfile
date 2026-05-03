FROM osrf/ros:humble-desktop-full

# Evitar prompts interactivos
ENV DEBIAN_FRONTEND=noninteractive

# Instalar dependencias esenciales
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-gazebo-plugins \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-xacro \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher-gui \
    ros-humble-rviz2 \
    ros-humble-teleop-twist-keyboard \
    python3-pip \
    git \
    wget \
    mesa-utils \
    libgl1-mesa-dri \
    libgl1-mesa-glx \
    && rm -rf /var/lib/apt/lists/*

# Instalar utilidades de Fuel para descargar modelos
RUN pip3 install requests

# Crear el workspace de ROS
WORKDIR /ros2_ws
RUN mkdir -p /ros2_ws/src

# Configurar el entorno
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "if [ -f /ros2_ws/install/setup.bash ]; then source /ros2_ws/install/setup.bash; fi" >> ~/.bashrc
RUN echo "source /usr/share/gazebo/setup.bash" >> ~/.bashrc

ENV XDG_RUNTIME_DIR=/tmp/runtime-root
RUN mkdir -p /tmp/runtime-root && chmod 700 /tmp/runtime-root

WORKDIR /ros2_ws
CMD ["bash"]
