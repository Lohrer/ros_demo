#include "DoorStateDetector.hpp"
#include <algorithm>  // std::sort
#include <cmath>      // round

namespace people_counter
{
  DoorStateDetector::DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    door_dist_ = -1.0; // Negative means uncalibrated
    sub_scan_ = n.subscribe<sensor_msgs::LaserScan>("scan", 10, &DoorStateDetector::recvScan, this);
    pub_door_open_ = n.advertise<std_msgs::Bool>("door_open", 1);
    pub_scan_ = n.advertise<sensor_msgs::LaserScan>("scan_door", 1);
    srv_.setCallback(boost::bind(&DoorStateDetector::reconfig, this, _1, _2));
  }

  void DoorStateDetector::recvScan(const sensor_msgs::LaserScanConstPtr& msg)
  {
    // Reduce scan to just the door and surrounding flat wall
    sensor_msgs::LaserScan door_scan = *msg;
    door_scan.angle_min = cfg_.angle_min;
    door_scan.angle_max = cfg_.angle_max;
    door_scan.ranges.clear();
    door_scan.intensities.clear();
    int min_idx = (door_scan.angle_min - msg->angle_min) / msg->angle_increment;
    int max_idx = msg->ranges.size() - (msg->angle_max - door_scan.angle_max) / msg->angle_increment;
    float sum = 0.0;
    float max = 0.0;
    for (int i = min_idx; i < max_idx; i++) {
      door_scan.ranges.push_back(msg->ranges[i]);
      sum += msg->ranges[i];
      if (msg->ranges[i] > max && msg->ranges[i] < msg->range_max) {
        max = msg->ranges[i];
      }
    }
    float avg = sum / door_scan.ranges.size();

    // Sort ranges shortest to farthest
    std::vector<float> sorted_ranges;
    for (int i = 0; i < door_scan.ranges.size(); i++) {
      if (door_scan.ranges[i] < door_scan.range_max) {
        sorted_ranges.push_back(door_scan.ranges[i]);
      }
    }
    std::sort(std::begin(sorted_ranges), std::end(sorted_ranges));
    size_t idx = (size_t)std::round(sorted_ranges.size()*cfg_.range_percentile);
    float val = sorted_ranges[idx];

    // First time, calibrate door distance
    if (door_dist_ < 0) {
      door_dist_ = val;
    }

    std_msgs::Bool state_msg;
    if (val - door_dist_ > cfg_.open_thresh) {
      state_msg.data = true;
      for (int i = min_idx; i < max_idx; i++) {
        door_scan.intensities.push_back(1);
      }
    } else {
      state_msg.data = false;
      for (int i = min_idx; i < max_idx; i++) {
        door_scan.intensities.push_back(0);
      }
    }

    pub_door_open_.publish(state_msg);
    pub_scan_.publish(door_scan);
  }

  void DoorStateDetector::reconfig(DoorStateDetectorConfig& config, uint32_t level)
  {
    // Verify min/max angles make sense
    if (config.angle_max < config.angle_min) {
      config.angle_max = config.angle_min;
    }
    if (config.calibrate) {
      config.calibrate = false;
      door_dist_ = -1;
    }
    cfg_ = config;
  }
}
