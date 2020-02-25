cmake_minimum_required(VERSION 2.8.3)
project(people_counter)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  nodelet
  std_msgs
  sensor_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_library(door_detector
  src/door_detector_nodelet.cpp
  src/DoorDetector.cpp
)
add_dependencies(door_detector
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(door_detector
  ${catkin_LIBRARIES}
)

add_executable(door_detector_node
  src/door_detector_node.cpp
  src/DoorDetector.cpp
)
add_dependencies(door_detector_node
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(door_detector_node
  ${catkin_LIBRARIES}
)

install(TARGETS door_detector door_detector_node
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

install(FILES nodelets.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
