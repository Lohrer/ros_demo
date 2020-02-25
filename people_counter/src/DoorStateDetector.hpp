#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "DoorStateDetector.hpp"

namespace people_counter
{
  class DoorStateDetector
  {
    public:
      DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:

  };
}
