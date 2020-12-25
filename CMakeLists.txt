cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(kalman_filter_exercises)

find_package(Eigen3 REQUIRED)

add_executable(kalman_filter_exercise_1 kalman_filter_exercise_1.cpp)
target_link_libraries (kalman_filter_exercise_1 Eigen3::Eigen)
