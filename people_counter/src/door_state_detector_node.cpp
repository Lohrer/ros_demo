#include <ros/ros.h>
#include "DoorStateDetector.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "door_state_detector_node");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");

  people_counter::DoorStateDetector node(n, pn);

  ros::spin();
}
