cmake_minimum_required(VERSION 3.3)
project(Hanks_Homework_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("C:\\Users\\Hanko\\Documents\\C++ Files\\CPT-180-27-Assignment-4-Analysis-Tool\\helper")
link_directories("C:\\Users\\Hanko\\Documents\\C++ Files\\CPT-180-27-Assignment-4-Analysis-Tool\\helper")
set(SOURCE_FILES main.cpp)
add_executable(Hanks_Homework_ ${SOURCE_FILES})

target_link_libraries(Hanks_Homework_ helper)


