cmake_minimum_required(VERSION 3.5)
project(bayan VERSION 0.1.0)

get_filename_component(TARGET_SUBNAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(TARGET "${CMAKE_PROJECT_NAME}_${TARGET_SUBNAME}")

file( GLOB_RECURSE TARGET_HEADERS *.h)
file( GLOB_RECURSE TARGET_SRCS *.cpp )

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(bayan ${TARGET_HEADERS} ${TARGET_SRCS} )
target_link_libraries(bayan ${Boost_PROGRAM_OPTIONS_LIBRARY})

set_target_properties(bayan PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)


if (WIN32)
  install(
    PROGRAMS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/${TARGET}.exe"
    DESTINATION bin CONFIGURATIONS Release RENAME bayan.exe)
else()
  message(STATUS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET}")
  install(TARGETS bayan RUNTIME DESTINATION bin)
  execute_process(COMMAND rm --force ${CMAKE_BINARY_DIR}/bayan)
  execute_process(COMMAND ln -s "${CPACK_INSTALL_PREFIX}/${CPP_OTUS_INSTALL_BIN_DIR}/${TARGET}" ${CMAKE_BINARY_DIR}/bayan)
  install(FILES ${CMAKE_BINARY_DIR}/bayan DESTINATION bin)
endif()
