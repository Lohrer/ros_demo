#pragma once

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>

namespace people_counter
{
  enum State {
    IDLE,
    PERSON_AT_DOOR_LEAVING,
    PERSON_AT_DOOR_ENTERING,
    DOOR_OPEN_AFTER_PERSON,
    DOOR_OPEN_BEFORE_PERSON,
    DOOR_CLOSING_LEAVING,
    DOOR_CLOSING_ENTERING,
  };
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
      int32_t count_;
      State state_;

      // publishers and subscribers
      ros::Publisher  pub_num_people_;
      ros::Subscriber sub_person_at_door_;
      ros::Subscriber sub_door_open_;
  };
}
