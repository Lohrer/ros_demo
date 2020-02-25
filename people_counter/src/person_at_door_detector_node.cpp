#include <ros/ros.h>
#include "PersonAtDoorDetector.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "person_at_door_detector_node");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");

  people_counter::PersonAtDoorDetector node(n, pn);

  ros::spin();
}
