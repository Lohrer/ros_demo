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

    rosed people_counter launch/live.launch

## Making a node

### Where does a C++ node go?

    roscd people_counter

    tree

### What do you put in a node?

1. Add subscriber for /laser/scan
1. Build the door_state_detector
1. Add door_state_detector to the launch file
1. Run the system

    catkin_make && roslaunch people_counter launch/live.launch

### What about things that change? We don't want to compile them
1. Add dynamic_reconfigure
1. Add publisher for /door/scan, for visualizing our detection
1. Test dynamic angle modification

    rosrun rqt_reconfigure rqt_reconfigure

1. Add angle parameters to the launch file, so we don't have to do this every time
1. Test parameters

### TODO: add final details of mode