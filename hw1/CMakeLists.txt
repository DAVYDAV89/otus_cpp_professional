cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Build version")
set(PROJECT_VERSION "0.1" 0.0.${PATCH_VERSION})

project(hw1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw1 main.cpp)
