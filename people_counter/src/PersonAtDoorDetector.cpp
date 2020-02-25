#include "PersonAtDoorDetector.hpp"

namespace people_counter
{
  PersonAtDoorDetector::PersonAtDoorDetector(ros::NodeHandle& n, ros::NodeHandle& pn) {
    pub_person_at_door_ = n.advertise<std_msgs::Bool>("person_at_door", 10);
    sub_poses_ = n.subscribe("poses", 10, &PersonAtDoorDetector::recvPoses, this);
    // TODO: add parameter that tells us dimensions and location of the door
  }

// TODO: make this use the actual poses message!!
void PersonAtDoorDetector::recvPoses(const std_msgs::Bool::ConstPtr & msg) {
  // TODO: filter poses that are near the door
}


}
