cmake_minimum_required(VERSION 3.15)
project(AlgoInCpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

ADD_SUBDIRECTORY(TwoPointers)
ADD_SUBDIRECTORY(DFS)
ADD_SUBDIRECTORY(BFS)

add_executable(AlgoInCpp main.cpp)
