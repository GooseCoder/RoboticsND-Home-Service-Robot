#!/bin/sh
export ROBOT_INITIAL_POSE="-x 0 -y -3 -Y 1.5"
xterm -e "roslaunch my_robot turtlebot_world.launch" &
sleep 5
xterm -e "roslaunch my_robot amcl_map.launch" &
sleep 5
xterm -e "roslaunch my_robot view_navigation.launch" &
sleep 5
xterm -e "rosrun add_markers add_markers_timer"
