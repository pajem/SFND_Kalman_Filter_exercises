cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(kalman_filter_lidar)

find_package(Eigen3 REQUIRED)

add_executable(kalman_filter_lidar
    main.cpp
    kalman_filter.cpp
    tracking.cpp
)
target_link_libraries (kalman_filter_lidar Eigen3::Eigen)
