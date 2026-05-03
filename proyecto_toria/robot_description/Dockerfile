FROM osrf/ros:humble-desktop-full

# Evitar prompts interactivos
ENV DEBIAN_FRONTEND=noninteractive

# Instalar dependencias esenciales para simulación y navegación
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-xacro \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher \
    ros-humble-rviz2 \
    git \
    wget \
    mesa-utils \
    libgl1-mesa-dri \
    libgl1-mesa-glx \
    && rm -rf /var/lib/apt/lists/*

# Crear el workspace de ROS
WORKDIR /ros2_ws/src

# Configurar el entorno al iniciar sesión
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# El comando por defecto ahora es simplemente bash
CMD ["bash"]
