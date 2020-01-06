cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#message("CMAKE_CXX_FLAGS:" ${CMAKE_CXX_FLAGS})

project(cpp)

file(GLOB srcFiles
    "src/*.cpp"
    "src/*.hpp")

add_executable(${PROJECT_NAME} ${srcFiles})

find_package (Threads)
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
# add if is used:
# uuid)
