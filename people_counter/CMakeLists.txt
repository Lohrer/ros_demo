cmake_minimum_required(VERSION 2.8.3)
project(people_counter)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(door_state_detector
  src/door_state_detector_node.cpp
  src/DoorStateDetector.cpp
)
add_dependencies(door_state_detector
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(door_state_detector
  ${catkin_LIBRARIES}
)

install(TARGETS door_state_detector
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(PROGRAMS
#     scripts/myscript1
#     nodes/mynode1
#     nodes/mynode2
     DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch yaml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
