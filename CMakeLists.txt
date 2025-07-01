cmake_minimum_required(VERSION 3.10)
project(MyProject)

include_directories(include)
add_executable(myprogram src/main.cpp src/utils.cpp)