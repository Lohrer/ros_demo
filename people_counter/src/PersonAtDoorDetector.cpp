#include "PersonAtDoorDetector.hpp"

namespace people_counter
{
  PersonAtDoorDetector::PersonAtDoorDetector(ros::NodeHandle& n, ros::NodeHandle& pn) : it_(n) {
    // TODO: add subscribers and publishers
    /*
    pub_person_at_door_ = n.advertise<std_msgs::Bool>("person_at_door", 10);
    sub_poses_ = n.subscribe("people", 10, &PersonAtDoorDetector::recvPoses, this);
    */
    // TODO: add debugging
    /*
    sub_image_ = it_.subscribe("image", 1, &PersonAtDoorDetector::recvImage, this);
    pub_image_ = it_.advertise("door_image", 1);
    */
    // TODO: add dynamic reconfigure
    /*
    srv_.setCallback(boost::bind(&PersonAtDoorDetector::reconfig, this, _1, _2));
    */
  }

void PersonAtDoorDetector::recvPoses(const openpose_ros_msgs::OpenPoseHumanList::ConstPtr & msg) {
  std_msgs::Bool out;
  out.data = false;
  // TODO: save the person list so we can draw them on our image?
  /*
  people_ = msg->human_list;
  */
  // TODO: check if a person is inside the door
  /*
  for (const auto& person : msg->human_list) {
    const auto& box = person.body_bounding_box;
     if (box.x > cfg_.x && box.y > cfg_.y && box.width < cfg_.width && box.height < cfg_.height) {
       out.data = true;
       break;
     }
  }
  */
  pub_person_at_door_.publish(out);
}

static void drawBox(cv_bridge::CvImagePtr cv_ptr, const float x1, const float y1, const float x2, const float y2, const cv::Scalar& color) {
    // top
    cv::line(cv_ptr->image, cv::Point(x1, y1), cv::Point(x2, y1), color, 2);
    // right
    cv::line(cv_ptr->image, cv::Point(x2, y1), cv::Point(x2, y2), color, 2);
    // left
    cv::line(cv_ptr->image, cv::Point(x1, y1), cv::Point(x1, y2), color, 2);
    // bottom
    cv::line(cv_ptr->image, cv::Point(x1, y2), cv::Point(x2, y2), color, 2);
}

void PersonAtDoorDetector::recvImage(const sensor_msgs::ImageConstPtr& msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }

  // TODO: draw the people detected
  /*
  const cv::Scalar RED(0, 0, 255);
  for (const auto& person : people_) {
    const auto& box = person.body_bounding_box;
    drawBox(cv_ptr, box.x, box.y, box.x + box.width, box.y + box.height, RED);
  }
  */

  // TODO: draw the outline of the door on the image, so we can visualize the configuration
  /*
  if (cv_ptr->image.rows == 960 && cv_ptr->image.cols == 1280) {
    int x1 = cfg_.x;
    int y1 = cfg_.y;
    int x2 = cfg_.x + cfg_.width;
    int y2 = cfg_.y + cfg_.height;
    const cv::Scalar GREEN(0, 255, 0);
    drawBox(cv_ptr, x1, y1, x2, y2, GREEN);
  } else {
    ROS_WARN_ONCE("image size is %ux%u, expected 1280x960", cv_ptr->image.rows, cv_ptr->image.cols);
  }
  */
  // TODO: output modified image
  /*
  pub_image_.publish(cv_ptr->toImageMsg());
  */

}

// TODO: add dynamic reconfigure
/*
void PersonAtDoorDetector::reconfig(PersonAtDoorDetectorConfig& config, uint32_t level) {
  int right = config.x + config.width;
  int bottom = config.y + config.height;
  // Make sure the door fits in the camera image
  if (right >= 1280) {
    config.width = 1280 - 1 - config.x;
  }
  if (bottom >= 960) {
    config.height = 960 - 1 - config.y;
  }
  cfg_ = config;
}
*/
}
