#include "PeopleCounter.hpp"

namespace people_counter
{
  PeopleCounter::PeopleCounter(ros::NodeHandle& n, ros::NodeHandle& pn)
  : door_open_(false),
    person_at_door_(false),
    state_(IDLE)
  {
    pub_num_people_ = n.advertise<std_msgs::Int32>("num_people", 10);
    sub_door_open_ = n.subscribe("door_open", 10, &PeopleCounter::recvDoorOpen, this);
    sub_person_at_door_ = n.subscribe("person_at_door", 10, &PeopleCounter::recvPersonAtDoor, this);
    pn.param<int32_t>("initial_count", count_, 0);
    ROS_INFO_STREAM("starting with an initial count of " << count_ << " people");
  }

void PeopleCounter::recvPersonAtDoor(const std_msgs::Bool::ConstPtr & msg) {
  person_at_door_ = msg->data;
  runStateMachine();
}

void PeopleCounter::recvDoorOpen(const std_msgs::Bool::ConstPtr & msg) {
  door_open_ = msg->data;
  runStateMachine();
}

void PeopleCounter::runStateMachine() {
  switch(state_) {
  case IDLE:
    if (person_at_door_) {
      state_ = PERSON_AT_DOOR_LEAVING;
      ROS_INFO("PERSON_AT_DOOR_LEAVING");
    } else if (door_open_) {
      state_ = DOOR_OPEN_BEFORE_PERSON;
      ROS_INFO("DOOR_OPEN_BEFORE_PERSON");
    }
    break;
  case DOOR_OPEN_BEFORE_PERSON:
    if (person_at_door_) {
      state_ = PERSON_AT_DOOR_ENTERING;
      ROS_INFO("PERSON_AT_DOOR_ENTERING");
    }
    break;
  case PERSON_AT_DOOR_ENTERING:
    if (!door_open_) {
      state_ = IDLE;
      ROS_INFO("IDLE");
      count_++;
      ROS_INFO_STREAM("count=" << count_);
    }
    break;
  case PERSON_AT_DOOR_LEAVING:
    if (door_open_) {
      state_ = DOOR_OPEN_AFTER_PERSON;
      ROS_INFO("DOOR_OPEN_AFTER_PERSON");
    }
    break;
  case DOOR_OPEN_AFTER_PERSON:
    if (!door_open_) {
      state_ = IDLE;
      ROS_INFO("IDLE");
      if (count_ > 0) {
	count_--;
	ROS_INFO_STREAM("count=" << count_);
      } else {
	ROS_ERROR("Detected negative people");
      }
    }
    break;
  }
  std_msgs::Int32 msg;
  msg.data = count_;
  pub_num_people_.publish(msg);
}

}
