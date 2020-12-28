# Udacity Robotics Nanodegree
## Home Service Robot

Home Service Robot project for the Robotics Nanodegree Program.

## Description 
```
.
├── Readme.md
├── .catkin_workspace
├── .gitignore
├── .gitmodules
└── src
    ├── CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
    ├── map
    │   ├── map.pgm
    │   ├── map.pgm.bck
    │   └── map.yaml
    ├── my_robot
    │   ├── CMakeLists.txt
    │   ├── config
    │   │   ├── base_local_planner_params.yaml
    │   │   ├── costmap_common_params.yaml
    │   │   ├── global_costmap_params.yaml
    │   │   ├── local_costmap_params.yaml
    │   │   └── __MACOSX
    │   ├── launch
    │   │   ├── amcl_map.launch
    │   │   ├── keyboard_teleop.launch
    │   │   ├── turtlebot_world.launch
    │   │   └── view_navigation.launch
    │   ├── maps
    │   │   ├── map.pgm
    │   │   ├── map.pgm.bck
    │   │   └── map.yaml
    │   ├── meshes
    │   │   └── hokuyo.dae
    │   ├── my_robot.rviz
    │   ├── package.xml
    │   ├── rviz
    │   │   └── navigation_with_markers.rviz
    │   ├── urdf
    │   │   ├── my_robot.gazebo
    │   │   └── my_robot.xacro
    │   └── worlds
    │       ├── empty.world
    │       └── HomeFirstFloor.world
    ├── add_markers
    │   ├── CMakeLists.txt
    │   ├── package.xml
    │   └── src
    │       ├── add_markers.cpp
    │       └── add_markers_timer.cpp
    ├── pick_objects
    │   ├── CMakeLists.txt
    │   ├── package.xml
    │   └── src
    │       └── pick_objects.cpp
    ├── scripts
    │   ├── add_markers.sh
    │   ├── home_service.sh
    │   ├── launch.sh
    │   ├── pick_objects.sh
    │   ├── test_navigation.sh
    │   └── test_slam.sh
    ├── pgm_map_creator
    ├── slam_gmapping
    ├── turtlebot
    ├── turtlebot_interactions
    └── turtlebot_simulator
```
The project has the following packages:

* The "add_markers" package provides the functions required to mark the pickup position and dropzone location on the map. It decides if the markers are visible or not by calculating the current position of the robot

* The "pick_onjects" package sets the target points and gives the order to move the robot to reach those target locations, first to pick up the cargo and then to unload the cargo on the dropzone.

* The "my_world" package has the launch files to start the world and set the initial configuration values, also is in charge to put the robot on that environment.

* The scripts folder stores the scripts to initialize the different project steps, there are tests for the pick-objects and add-markers packages and alsot the main home_service.sh script that runs the main pick and drop simulation. 

Alo the following supporting packages are used on the application:

* gmapping to provide the SLAM based map generation.

* turtlebot the classic robot that navigates the simulated world.

* turtlebot_simulator integrates the gazebo simulator with the turtlebot

* turtlebot_interactions library that allows user side interaction with the turtlebot 

## Setup

First clone the repository including the submodules

```
$ git clone --recurse-submodules git@github.com:GooseCoder/RoboticsND-Home-Service-Robot.git
```

## How to run

First compile and source the project and also ensure that all the files on the scripts folder has execution permissions.

```
$ catkin_make
$ source devel/setup.bash
```

Add markers demo script, it should show the marker in the original position then change it to the drop zone after 5 seconds.

```
$ cd src/scripts
$ ./add_markers.sh
```

Pick objects demo script.

```
$ cd src/scripts
$ ./pick_objects.sh
```

After that you can make the robot perform simultaneous localization and mapping (SLAM).

```
$ cd src/scripts
$ ./test_slam.sh
```

Then you send the robot to do navigation tasks

```
$ cd src/scripts
$ ./test_navigation.sh
```

Finally you can send the robot to retrieve a marker and return to a drop off zone

```
$ cd src/scripts
$ ./home_service.sh
```

