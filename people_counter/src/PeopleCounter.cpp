#include "PeopleCounter.hpp"

namespace people_counter
{
  PeopleCounter::PeopleCounter(ros::NodeHandle& n, ros::NodeHandle& pn)
  : door_open_(false),
    person_at_door_(false)
  {
    pub_num_people_ = n.advertise<std_msgs::Int16>("num_people", 10);
    sub_door_open_ = n.subscribe("door_open", 10, &PeopleCounter::recvDoorOpen, this);
    sub_door_open_ = n.subscribe("person_at_door", 10, &PeopleCounter::recvPersonAtDoor, this);
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
    // TODO: add state machine
}

}
