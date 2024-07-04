cmake_minimum_required(VERSION 3.21)
project(design_method)

set(CMAKE_CXX_STANDARD 14)

add_executable(simpleFactory main.cpp)
add_executable(factory factory.cpp)
add_executable(abstractFactory abstractFactory.cpp)
