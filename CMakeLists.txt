cmake_minimum_required(VERSION 3.3)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(
    ./include
)
set(SOURCE_FILES src/main.cpp src/dynamic_programming.cpp src/dynamic_programming.cpp include/dynamic_programming.h src/main.cpp)
add_executable(algorithms ${SOURCE_FILES} src/dynamic_programming.cpp include/dynamic_programming.h)