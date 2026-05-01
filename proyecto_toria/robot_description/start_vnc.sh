#!/bin/bash
set -e
export DISPLAY=:1
Xvfb :1 -screen 0 1280x800x24 &
sleep 2
fluxbox &
sleep 2
x11vnc -display :1 -nopw -forever -quiet -listen localhost &
sleep 2
/usr/share/novnc/utils/launch.sh --vnc localhost:5900 --listen 6080 &
sleep 2
source /opt/ros/humble/setup.bash
exec bash
