cmake_minimum_required(VERSION 3.15)
project(graphite_tb)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)

add_executable(graphite_tb src/main.cpp)
target_link_libraries(graphite_tb Eigen3::Eigen)
