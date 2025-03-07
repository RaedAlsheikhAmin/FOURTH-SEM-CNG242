cmake_minimum_required(VERSION 3.25)
project(raed)

set(CMAKE_CXX_STANDARD 17)

add_executable(raed main.cpp Company.cpp Vehicle.cpp car.cpp Bus.cpp Branch.cpp)
