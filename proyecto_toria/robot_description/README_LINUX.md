# Guía de Ejecución en Linux (Arch/Manjaro)

Este proyecto está optimizado para ejecutarse en un contenedor Docker compartiendo el servidor X11 de tu sistema Linux.

## Requisitos previos

1.  **Docker y Docker Compose** instalados.
2.  **xhost** instalado (`sudo pacman -S xorg-xhost`).

## Pasos para ejecutar la simulación

1.  **Permitir acceso a X11:**
    Desde tu terminal (zsh/bash), ejecuta:
    ```bash
    xhost +local:docker
    ```

2.  **Construir y levantar el contenedor:**
    Entra en la carpeta `robot_description` y ejecuta:
    ```bash
    docker-compose up -d --build
    ```

3.  **Entrar al contenedor:**
    ```bash
    docker exec -it ros2_hospital_container bash
    ```

4.  **Compilar el workspace (dentro del contenedor):**
    ```bash
    colcon build --symlink-install
    source install/setup.bash
    ```

5.  **Lanzar la simulación:**
    ```bash
    ros2 launch hospital_robot hospital_sim.launch.py
    ```

## Notas adicionales
- El robot aparecerá en Gazebo y RViz se abrirá automáticamente.
- Si no ves el robot en RViz, asegúrate de que el "Fixed Frame" esté en `base_footprint`.
- Puedes mover el robot usando `ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/hospital_bot/cmd_vel`.
