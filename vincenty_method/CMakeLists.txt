cmake_minimum_required(VERSION 3.5)
project(vincenty_method)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(
    main
    main.cpp
)