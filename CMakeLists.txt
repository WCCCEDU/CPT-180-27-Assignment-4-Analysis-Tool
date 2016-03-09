cmake_minimum_required(VERSION 3.3)
project(Seraching)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp search.h)
add_executable(Seraching ${SOURCE_FILES})