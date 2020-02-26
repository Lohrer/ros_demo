#include "DoorStateDetector.hpp"

namespace people_counter
{
  DoorStateDetector::DoorStateDetector(ros::NodeHandle& n, ros::NodeHandle& pn)
  {
    first_avg_ = -1;
    state_prev_ = false;
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
    //ROS_INFO_STREAM("max: " << max);

    // First time, calibrate door distance
    if (first_avg_ < 0) {
      first_avg_ = max;
    }

    std_msgs::Bool state_msg;

    // Verify sane values (someone isn't blocking lidar)
    /*if (avg - first_avg_ < -2) { // 2 meters closer than normal, hmm...
      state_msg.data = state_prev_;
      for (int i = min_idx; i < max_idx; i++) {
        door_scan.intensities.push_back(state_prev_ ? 1 : 0);
      }
    } else if (avg - first_avg_ > 1) {
      state_msg.data = true;
      for (int i = min_idx; i < max_idx; i++) {
        door_scan.intensities.push_back(1);
      }
    } else {
      state_msg.data = false;
      for (int i = min_idx; i < max_idx; i++) {
        door_scan.intensities.push_back(0);
      }
    }*/
    if (max - first_avg_ > 1) {
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
    state_prev_ = state_msg.data;

    pub_door_open_.publish(state_msg);
    pub_scan_.publish(door_scan);
  }

  void DoorStateDetector::reconfig(DoorStateDetectorConfig& config, uint32_t level)
  {
    // Verify min/max angles make sense
    if (config.angle_max < config.angle_min) {
      config.angle_max = config.angle_min;
    }
    cfg_ = config;
  }
}
