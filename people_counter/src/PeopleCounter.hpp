#pragma once

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include "PeopleCounter.hpp"

namespace people_counter
{
  class PeopleCounter
  {
    public:
      PeopleCounter(ros::NodeHandle& n, ros::NodeHandle& pn);

    private:
      void recvPersonAtDoor(const std_msgs::Bool::ConstPtr & msg);
      void recvDoorOpen(const std_msgs::Bool::ConstPtr & msg);
      void runStateMachine();

      // State machine
      bool person_at_door_;
      bool door_open_;

      // publishers and subscribers
      ros::Publisher  pub_num_people_;
      ros::Subscriber sub_person_at_door_;
      ros::Subscriber sub_door_open_;
  };
}
