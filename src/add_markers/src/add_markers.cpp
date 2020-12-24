#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>
#include <string>

float pickUpPos[2] = {2.5, 3.5};
float dropOffPos[2] = {-3.0, -6.0};

bool itemPickedUp = false;
bool itemDroppedOff = false;

std::string status = "iddle";
// 
void odomSensorCallback(const nav_msgs::Odometry::ConstPtr& msg) {
  double robotX = msg->pose.pose.position.x;
  double robotY = msg->pose.pose.position.y;
  
  double distanceToPickup = sqrt(pow(robotX - pickUpPos[0], 2) + pow(robotY - pickUpPos[1], 2));
  double distanceToDropOff = sqrt(pow(robotX - dropOffPos[0], 2) + pow(robotY - dropOffPos[1], 2));  

  if (distanceToPickup < 0.5) {
    status = "in-transit";
  }

  if (distanceToDropOff < 0.7) {
    status = "arrived";
  }
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Subscriber odom_sub = n.subscribe("odom", 100, odomSensorCallback);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  visualization_msgs::Marker marker;

  // Initial shape type set to cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  // Set the frame ID and timestamp.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();
  // Set the namespace and id for this marker to avoid collisions.
  marker.ns = "cube";
  marker.id = 0;
  // Set the marker type. This can change into different shapes.
  marker.type = shape;
  // Setting the pose of the marker.  This is a full 6DOF pose relative to the frame/time
  marker.pose.position.x = pickUpPos[0];
  marker.pose.position.y = pickUpPos[1];
  marker.pose.position.z = 0;
  // Marker orientation
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;
  // Set the color to blue with no transparency
  marker.color.r = 1.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();
  while (ros::ok())
  {
    // Publishing the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    
    if (status == "iddle")
    {
      marker.action = visualization_msgs::Marker::ADD;
      marker_pub.publish(marker);
    }
    else if (status == "in-transit")
    {
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
    }
    else
    {
      marker.pose.position.x = dropOffPos[0];
      marker.pose.position.y = dropOffPos[1];
      marker.action = visualization_msgs::Marker::ADD;
      marker_pub.publish(marker);
    }
    
    ros::spinOnce();
  }
}
