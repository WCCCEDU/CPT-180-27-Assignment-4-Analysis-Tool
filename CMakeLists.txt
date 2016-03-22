cmake_minimum_required(VERSION 3.3)
project(CPT_180_27_Assignment_4_Analysis_Tool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp header.h)
add_executable(CPT_180_27_Assignment_4_Analysis_Tool ${SOURCE_FILES})