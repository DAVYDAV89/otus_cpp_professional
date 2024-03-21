cmake_minimum_required(VERSION 3.5)

project(bulk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bulk
main.cpp
interface.h
implementation.cpp
)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")

set(CPACK_PACKAGE_NAME "bulk")
set(CPACK_PACKAGE_VERSION "1.0.2024")
set(CPACK_PACKAGE_CONTACT "Roman Davydov")
set(CMAKE_SYSTEM_NAME "Linux Mint")
include(CPack)
