#pragma once

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <sensor_msgs/LaserScan.h>
#include "DoorStateDetector.hpp"

// Dynamic Reconfigure
#include <dynamic_reconfigure/server.h>
#include <people_counter/DoorStateDetectorConfig.h>

namespace people_counter
{
  class DoorStateDetector
  {
    public:
      DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      void recvScan(const sensor_msgs::LaserScanConstPtr& msg);
      void reconfig(DoorStateDetectorConfig& config, uint32_t level);

      ros::Subscriber sub_scan_;
      ros::Publisher pub_door_open_;
      ros::Publisher pub_scan_;

      dynamic_reconfigure::Server<DoorStateDetectorConfig> srv_;
      DoorStateDetectorConfig cfg_;

      float door_dist_;
  };
}
