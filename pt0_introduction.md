# We want to make a people in room counter
## What do we need to detect? (open question)
1. Door open / closed state
1. People tracker / identification

## What sensor should we use?(open question)
1. Camera
1. LIDAR

## What should this system look like? (interactive)
1. Draw sensors + lots of space between
1. Draw people count
1. Use printeout as guide

## How should we implement this?
1. MATLAB?
   1. No special drivers (usb can, but not lidar or fancy camera)
   1. built in image processing tools
   1. good visualizations
   1. slow
1. C++?
    1. efficient
    1. use low level camera library + opencv
    1. write parser for lidar
    1. no visualizations/ roll your own
    1. complicated setup
1. ROS
    1. efficient
    1. drivers for most sensors even the fancy ones
    1. great sensor visualization tools
    1. modular (scales well for when project gets bigger)

## Show ros system diagram

![system diagram](https://github.com/Lohrer/ros_demo/raw/master/ros_system_diagram.png)
