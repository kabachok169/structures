cmake_minimum_required(VERSION 3.8)
project(Lists)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp list.h array.h expanded_list.h)
add_executable(Lists ${SOURCE_FILES})