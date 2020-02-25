#include <ros/ros.h>
#include "PeopleCounter.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "people_counter_node");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");

  people_counter::PeopleCounter node(n, pn);

  ros::spin();
}
