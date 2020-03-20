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
      // Callbacks
      void recvScan(const sensor_msgs::LaserScanConstPtr& msg);
      void reconfig(DoorStateDetectorConfig& config, uint32_t level);

      // Subscribers/publishers
      ros::Subscriber sub_laser_;
      ros::Publisher pub_door_state_;
      ros::Publisher pub_scan_door_;

      // Dynamic reconfigure
      dynamic_reconfigure::Server<DoorStateDetectorConfig> srv_;
      DoorStateDetectorConfig cfg_;

      float door_dist_;
  };
}
