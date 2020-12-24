#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  float points[2][3] = { {2.5, 3.5, 1.0}, {-3.0, -6.0, 1.0} };

  int num_points = 2;

  for (int i=0; i < num_points; i++){
      goal.target_pose.pose.position.x = points[i][0];
      goal.target_pose.pose.position.y = points[i][1];
      goal.target_pose.pose.orientation.w = points[i][2];

      // Sending the target position
      ROS_INFO("Sending target position #%d", i);
      ac.sendGoal(goal);
      
      // Waiting for results
      ac.waitForResult();

      // If the robot arrived to the target position
      if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
          ROS_INFO("Target position #%d reached!", i);
      } else {
          // The robot didn't arrived'
          ROS_INFO("Failed to reach the target position.");   
      }
      // 5 seconds cycle
      ros::Duration(5.0).sleep();
  }

  return 0;
}
