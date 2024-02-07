cmake_minimum_required(VERSION 3.5)

project(ips LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ips 
main.cpp
)

install(TARGETS ips RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")

set(CPACK_PACKAGE_NAME "print_ips")
set(CPACK_PACKAGE_VERSION "1.0.2024")
set(CPACK_PACKAGE_CONTACT "Roman Davydov")
set(CMAKE_SYSTEM_NAME "Linux Mint")
include(CPack)
