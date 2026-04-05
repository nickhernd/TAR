# maze_pkg — Instrucciones de ejecución

## 1. Entrar al contenedor

```bash
./run.sh
```

Si necesitas abrir una terminal adicional al contenedor ya lanzado:
```bash
./connect_ros.sh
```

---

## 2. Source del entorno (cada nueva terminal)

```bash
source /opt/ros/humble/setup.bash
source /workspace/ros2_ws/install/setup.bash
```

> Si lo añadiste al `~/.bashrc` y hiciste `docker commit`, esto es automático.

---

## 3. Compilar el paquete

```bash
cd /workspace/ros2_ws
colcon build --packages-select maze_pkg
source install/setup.bash
```

---

## 4. Ejercicio 1 — Laberinto 1 con Waffle

**Terminal 1** — Simulación:
```bash
export TURTLEBOT3_MODEL=waffle
ros2 launch maze_pkg maze_1.launch.py
```

**Terminal 2** — Solver:
```bash
source /workspace/ros2_ws/install/setup.bash
export TURTLEBOT3_MODEL=waffle
ros2 run maze_pkg res_maze
```

---

## 5. Ejercicio 2 — Laberinto 2 con Waffle

**Terminal 1:**
```bash
export TURTLEBOT3_MODEL=waffle
ros2 launch maze_pkg maze_2.launch.py
```

**Terminal 2:**
```bash
source /workspace/ros2_ws/install/setup.bash
ros2 run maze_pkg res_maze
```

---

## 6. Ejercicio 3 — Repetir con Burger

Igual que los ejercicios anteriores pero cambiando el modelo:

```bash
export TURTLEBOT3_MODEL=burger
ros2 launch maze_pkg maze_1.launch.py
```

```bash
source /workspace/ros2_ws/install/setup.bash
ros2 run maze_pkg res_maze
```

---

## 7. Resetear la simulación (si el robot se atasca)

```bash
ros2 service call /reset_simulation std_srvs/srv/Empty "{}"
```

O desde la ventana de Gazebo: `Ctrl+R`

---

## 8. Parámetros ajustables en res_maze.py

| Parámetro       | Valor actual | Descripción                                         |
|-----------------|-------------|------------------------------------------------------|
| `LINEAR_SPEED`  | 0.12        | Velocidad lineal (m/s)                               |
| `ANGULAR_SPEED` | 0.40        | Velocidad angular de giro (rad/s)                    |
| `WALL_DIST`     | 0.40        | Distancia deseada a la pared izquierda (m)           |
| `FRONT_THRESH`  | 0.45        | Distancia mínima al frente antes de girar (m)        |
| `KP`            | 1.0         | Ganancia del control proporcional de seguimiento     |
| `MIN_TURN_TICKS`| 12          | Callbacks mínimos en estado de giro (~1.2 s a 10 Hz) |

Si el robot sigue girando en sitio: subir `MIN_TURN_TICKS` a 18-20.
Si gira demasiado y se pasa: bajarlo a 8-10.
