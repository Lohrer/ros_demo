#pragma once

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <sensor_msgs/LaserScan.h>
#include "DoorStateDetector.hpp"

namespace people_counter
{
  class DoorStateDetector
  {
    public:
      DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      void recvScan(const sensor_msgs::LaserScanConstPtr& msg);

      ros::Publisher pub_door_open_;
      ros::Subscriber sub_scan_;
  };
}
