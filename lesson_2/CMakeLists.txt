cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.${PATCH_VERSION})

project(ip_filter LANGUAGES CXX VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

add_executable(ip_filter main.cpp ipAddres.h)
add_executable(test_version_ip_filter main_test.cpp ipAddres.h)


set_target_properties(ip_filter test_version_ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)

#target_link_libraries(ip_filter
#    ip_filter_lib
#)


install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

target_link_libraries(test_version_ip_filter gtest)
add_test(test_version_ip_filter test_version_ip_filter)
