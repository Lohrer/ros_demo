#pragma once

#include <ros/ros.h>
#include "PersonAtDoorDetector.hpp"

// messages
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <openpose_ros_msgs/OpenPoseHumanList.h>

// image handling
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>

// dynamic reconfigure
#include <dynamic_reconfigure/server.h>
#include <people_counter/PersonAtDoorDetectorConfig.h>

namespace people_counter
{
  class PersonAtDoorDetector
  {
    public:
      PersonAtDoorDetector(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      void recvPoses(const  openpose_ros_msgs::OpenPoseHumanList::ConstPtr & msg);
      void recvImage(const sensor_msgs::ImageConstPtr& msg);
      void reconfig(PersonAtDoorDetectorConfig& config, uint32_t level);

      // publishers and subscribers
      ros::Publisher pub_person_at_door_;
      ros::Subscriber sub_poses_;

      // image handling
      image_transport::ImageTransport it_;
      image_transport::Subscriber sub_image_;
      image_transport::Publisher pub_image_;

      // saved people, for visualization
      std::vector<openpose_ros_msgs::OpenPoseHuman> people_;

      // dynamic reconfigure
      dynamic_reconfigure::Server<PersonAtDoorDetectorConfig> srv_;
      PersonAtDoorDetectorConfig cfg_;
  };
}
