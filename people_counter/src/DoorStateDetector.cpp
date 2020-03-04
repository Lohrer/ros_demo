#include "DoorStateDetector.hpp"
#include <algorithm>  // std::sort
#include <cmath>      // round

namespace people_counter
{
  DoorStateDetector::DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    //sub_ = n.subscribe<sensor_msgs::LaserScan>("sub", 10, &DoorStateDetector::recvSub, this);
    //pub_ = n.advertise<std_msgs::Bool>("pub", 1);
    //srv_.setCallback(boost::bind(&DoorStateDetector::reconfig, this, _1, _2));
  }

  // TODO: Receive messages
  //void DoorStateDetector::recvScan(const sensor_msgs::LaserScanConstPtr& msg)
  //{
    // TODO: Reduce scan to just the door and surrounding flat wall
    /*
    sensor_msgs::LaserScan door_scan = *msg;
    int min_idx = (cfg_.angle_min - msg->angle_min) / msg->angle_increment;
    int max_idx = msg->ranges.size() - (msg->angle_max - cfg_.angle_max) / msg->angle_increment;
    */

    // TODO: Sort ranges shortest to farthest, then pick the desired percentile

    // TODO: Calibrate?

    // TODO: Determine if door is open or not

    // TODO: Publish scan that has been reduced to just the door for visualization

    //std_msgs::Bool msg_out;
    //pub_.publish(msg_out);
  //}

  // TODO: Receive configuration changes
  //void DoorStateDetector::reconfig(DoorStateDetectorConfig& config, uint32_t level)
  //{
    // TODO: Verify min/max angles make sense
    // TODO: Calibrate
    //cfg_ = config;
  //}
}
