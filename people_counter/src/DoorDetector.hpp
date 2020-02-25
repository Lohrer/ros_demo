#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "DoorDetector.hpp"

namespace people_detector
{
  class DoorDetectorNode
  {
    public:
      DoorDetectorNode(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:

  };
}
