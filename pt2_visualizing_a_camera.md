# Using a camera to detect people at the door

## Wait what are we trying to do again?

    roscd people_counter/..
    feh -Z ros_system_diagram.png

## Where we left off

    roslaunch people_counter offline.launch

## Connecting openpose

    roslaunch openpose_ros openpose_ros.launch
    rosrun rqt_graph rqt_graph

### Taking an example launchfile and modifying it
- Add openpose_ros.launch contents to live.launch
- Turn off visualizations, they can be distracting

## Making a person at door detector
### Add necessary subscribers and publishers

    catkin_make
    roslaunch people_counter offline.launch
    rosrun rqt_graph rqt_graph

### Investigate open pose message
What can we use to detect a person?

    rostopic echo -c --noarr /people

### Add a bounding box for the peopl with visualization

    catkin_make
    roslaunch people_counter offline.launch

### How should we detect if a person is at the door?
### Add a bounding box to the door with visualization

    catkin_make
    roslaunch people_counter offline.launch

### Add check if a person is inside the bounding box

## Running the ros camera driver

    roslaunch camera_aravis simple_camera.launch

    rosrun rqt_image_view rqt_image_view

## Add the camera to live.launch

notice how fisheyed the camera looks, can we make it look better?

## Calibrating a camera
We can use a checkerboard of known size to figure out what the lens's distortion coefficients are 

    roslaunch camera_aravis simple_camera.launch

    rosrun camera_calibration cameracalibrator.py --size 8x6 --square 0.0257 image:=/camera/image camera:=/camera    

    /opt/ros/melodic/lib/camera_calibration/cameracalibrator.py --size 8x6 --square 0.0257 image:=/camera/image camera:=/camera

- calibrate finds the best camera distortion parameters to match the samples it took
- save saves the images so the calibration sequence can be redone
- image will be saved by camera when commit is clicked

## Rectifying the output all of the time

Try using image_proc:

   ROS_NAMESPACE=camera rosrun image_proc image_proc image_raw:=image

Lets add it to live.launch

## Questions?

