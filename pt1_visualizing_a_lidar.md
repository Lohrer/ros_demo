# Visualizing a LIDAR
## Manually launch the lidar node

### run the LIDAR

    rosrun urg_node urg_node

### run the roscore

    roscore

### show the LIDAR data

    rosrun rviz rviz

## Automatically do all of this with an equivalent launch file

    git checkout example/skeleton

    rosed people_counter live.launch

## Making a node

### Where does a C++ node go?

    roscd people_counter

    tree

### What do you put in a node?

1. Add subscriber for /laser/scan
1. Add publisher for /door_open (always publish False for now)
1. Build the door_state_detector
1. Add door_state_detector to the launch file
1. Run the system

    catkin_make && roslaunch people_counter live.launch

### What about things that change? We don't want to compile them

1. Add dynamic_reconfigure
1. Add publisher for /scan_door, for visualizing our detection
1. Test dynamic angle modification

    rosrun rqt_reconfigure rqt_reconfigure

1. Add angle parameters to the launch file, so we don't have to do this every time
1. Test parameters

### Detecting the door door state

1. Sort ranges, pick the range at a given percentile
1. Add parameters for range percentile and threshold
1. Add calibration to set the door distance
1. If a the Xth percentile of a set of ranges is farther away than the
   threshold, the door is open. Otherwise, it is closed.
