#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include "DoorDetector.hpp"

namespace people_detector
{

class DoorDetectorNodelet : public nodelet::Nodelet
{
public:
  DoorDetectorNodelet() {}
  ~DoorDetectorNodelet() {}

  void onInit(void) {
    node_.reset(new DoorDetectorNode(getNodeHandle(), getPrivateNodeHandle()));
  }

private:
  boost::shared_ptr<DoorDetectorNode> node_;
};

}

#if ROS_VERSION_MINOR > 12
PLUGINLIB_EXPORT_CLASS(people_detector::DoorDetectorNodelet, nodelet::Nodelet);
#else
PLUGINLIB_DECLARE_CLASS(people_detector, DoorDetectorNodelet, people_detector::DoorDetectorNodelet, nodelet::Nodelet);
#endif
