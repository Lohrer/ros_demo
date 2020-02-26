cmake_minimum_required(VERSION 2.8.3)
project(people_counter)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  std_msgs
  sensor_msgs
)

generate_dynamic_reconfigure_options(
  cfg/DoorStateDetector.cfg
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

################################################################################
# Door State Detector
################################################################################
add_executable(door_state_detector
  src/door_state_detector_node.cpp
  src/DoorStateDetector.cpp
)
add_dependencies(door_state_detector
  ${PROJECT_NAME}_gencfg
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(door_state_detector
  ${catkin_LIBRARIES}
)

################################################################################
# Person at Door Detector
################################################################################
add_executable(person_at_door_detector
  src/person_at_door_detector_node.cpp
  src/PersonAtDoorDetector.cpp
)
add_dependencies(person_at_door_detector
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(person_at_door_detector
  ${catkin_LIBRARIES}
)

################################################################################
# People Counter
################################################################################
add_executable(people_counter
  src/people_counter_node.cpp
  src/PeopleCounter.cpp
)
add_dependencies(people_counter
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(people_counter
  ${catkin_LIBRARIES}
)

################################################################################
# Installation rules
################################################################################
install(TARGETS door_state_detector person_at_door_detector people_counter
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY launch yaml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
