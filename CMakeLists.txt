cmake_minimum_required(VERSION 2.8)
# -std=c++0x for c++11 support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

# project name e.g. for qt-creator
project(Cpp)

add_executable(cpp
    main.cpp
)

