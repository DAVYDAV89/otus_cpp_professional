set(TARGET async_bulk)

file( GLOB TARGET_HEADERS *.h)
file( GLOB TARGET_SRCS *.cpp )

add_subdirectory(lib)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib") # делаем доступным файл async.h

add_executable(${TARGET} ${TARGET_HEADERS} ${TARGET_SRCS})
target_link_libraries(${TARGET} async)

set_target_properties(${TARGET} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  )

if (WIN32)
  install(
    PROGRAMS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/${TARGET}.exe"
    DESTINATION bin CONFIGURATIONS Release RENAME async_bulk.exe)
else()
  message(STATUS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET}")
  install(TARGETS async LIBRARY DESTINATION lib)
  install(FILES ${CMAKE_BINARY_DIR}/async_bulk
      PERMISSIONS  OWNER_READ OWNER_EXECUTE WORLD_READ WORLD_EXECUTE GROUP_READ GROUP_EXECUTE
      DESTINATION bin)
endif()


set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "async_bulk")
set(CPACK_PACKAGE_VERSION "1.0.2024")
set(CPACK_PACKAGE_CONTACT "Roman Davydov")
set(CMAKE_SYSTEM_NAME "Linux Mint")
include(CPack)


