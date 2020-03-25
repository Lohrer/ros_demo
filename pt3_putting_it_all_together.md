# Putting it all together and counting people

## Wait what are we trying to do again?

    roscd people_counter/..
    feh -Z ros_system_diagram.png

## Where we left off

    roslaunch people_counter offline.launch
    rostopic echo -c /person_at_door
    rostopic echo -c /door_open

## Making the actual people counter

### Add it to the launch file

    rosed people_counter offline.launch
    roslaunch people_counter offline.launch
    rqt_graph

### Add subscribers and publishers

    rosed people_counter PeopleCounter.cpp
    catkin_make

### Wait we have to make a state machine right?

Michael?

### Adding the state machine

    rosed people_counter PeopleCounter.cpp
    catkin_make
    roslaunch people_counter offline.launch

### Publishing the count output

    rosed people_counter PeopleCounter.cpp
    catkin_make
    roslaunch people_counter offline.launch
    rostopic echo /people_count

### Visualizing the count output easy

    rosed people_counter PeopleCounter.cpp
    catkin_make
    roslaunch people_counter offline.launch

### Tweaking things