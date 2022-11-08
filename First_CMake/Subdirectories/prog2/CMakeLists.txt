cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(prog2)

# Source files

set(SRC
    src/file.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib1/inc
)

add_executable(prog2 ${SRC})

target_link_libraries(prog2 lib1)

IF (NOT WIN32)
  target_link_libraries(prog2 m)
ENDIF()
