#include <ros/ros.h>
#include "DoorDetector.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "door_detector_node");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");

  people_detector::DoorDetectorNode node(n, pn);

  ros::spin();
}
