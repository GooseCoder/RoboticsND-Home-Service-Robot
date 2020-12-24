# Udacity Robotics Nanodegree
## Home Service Robot

Home Service Robot project for the Robotics Nanodegree Program.

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
$ ./test_navigation.sh
```

