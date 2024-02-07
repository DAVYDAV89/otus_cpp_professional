cmake_minimum_required(VERSION 3.5)

project(allocators LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(allocators 
main.cpp
myAllocator.h
myMap.h
)
