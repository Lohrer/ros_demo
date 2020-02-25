#include "DoorStateDetector.hpp"

namespace people_counter
{
  DoorStateDetector::DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    sub_scan_ = n.subscribe<sensor_msgs::LaserScan>("scan", 10, &DoorStateDetector::recvScan, this);
    pub_door_open_ = n.advertise<std_msgs::Bool>("door_open", 1);
  }

  void DoorStateDetector::recvScan(const sensor_msgs::LaserScanConstPtr& msg)
  {
    std_msgs::Bool state_msg;
    state_msg.data = false;
    pub_door_open_.publish(state_msg);
  }
}
