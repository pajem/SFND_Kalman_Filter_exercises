cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(kalman_filter)

find_package(Eigen3 REQUIRED)

add_executable(kalman_filter kalman_filter.cpp)
target_link_libraries (kalman_filter Eigen3::Eigen)
