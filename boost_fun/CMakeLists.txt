cmake_minimum_required(VERSION 3.5)
project(boost_fun)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(Boost COMPONENTS chrono REQUIRED)
add_executable(
    boost_fun 
    main.cpp
)
target_link_libraries(
   ${PROJECT_NAME}
   Boost::thread
 )