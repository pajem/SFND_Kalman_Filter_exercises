cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(jacobian)

find_package(Eigen3 REQUIRED)

add_executable(jacobian jacobian.cpp)
target_link_libraries (jacobian Eigen3::Eigen)
