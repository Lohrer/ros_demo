cmake_minimum_required(VERSION 2.8.3)
project(people_counter)

find_package(catkin REQUIRED)

catkin_package()

install(PROGRAMS
#     scripts/myscript1
#     nodes/mynode1
#     nodes/mynode2
     DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
