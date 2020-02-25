#pragma once

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include "PersonAtDoorDetector.hpp"

namespace people_counter
{
  class PersonAtDoorDetector
  {
    public:
      PersonAtDoorDetector(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      void recvPoses(const std_msgs::Bool::ConstPtr & msg);

      // publishers and subscribers
      ros::Publisher pub_person_at_door_;
      ros::Subscriber sub_poses_;
  };
}
