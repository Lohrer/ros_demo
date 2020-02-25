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

install(TARGETS door_state_detector person_at_door_detector people_counter
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY launch yaml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
