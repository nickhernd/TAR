FROM osrf/ros:humble-desktop-full

# Evitar prompts interactivos
ENV DEBIAN_FRONTEND=noninteractive

# Instalar dependencias para escritorio remoto vía web y diagnóstico
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-xacro \
    git \
    wget \
    fluxbox \
    x11vnc \
    xvfb \
    novnc \
    websockify \
    net-tools \
    mesa-utils \
    && rm -rf /var/lib/apt/lists/*

# Crear el workspace de ROS
WORKDIR /ros2_ws/src

# Configurar el entorno al iniciar sesión
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# Comando de inicio optimizado
CMD bash -c "\
    export DISPLAY=:1 && \
    Xvfb :1 -screen 0 1280x800x24 -ac +extension GLX +render -noreset & \
    sleep 3 && \
    fluxbox & \
    sleep 2 && \
    x11vnc -display :1 -nopw -forever -shared -bg -rfbport 5900 && \
    sleep 2 && \
    /usr/share/novnc/utils/launch.sh --vnc 127.0.0.1:5900 --listen 6080 & \
    sleep 2 && \
    source /opt/ros/humble/setup.bash && \
    exec bash"
