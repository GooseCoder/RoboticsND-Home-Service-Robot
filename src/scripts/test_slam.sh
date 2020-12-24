#!/bin/sh
export ROBOT_INITIAL_POSE="-x 0 -y -3 -Y 1.5"
xterm -e "roslaunch my_robot turtlebot_world.launch" &
sleep 5
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"
