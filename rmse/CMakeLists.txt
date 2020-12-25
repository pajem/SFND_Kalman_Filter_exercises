cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(rmse)

find_package(Eigen3 REQUIRED)

add_executable(rmse rmse.cpp)
target_link_libraries (rmse Eigen3::Eigen)
