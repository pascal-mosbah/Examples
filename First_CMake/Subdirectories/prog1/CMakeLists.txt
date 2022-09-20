cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(prog1)

# Source files

set(SRC
    src/prog1.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib1/inc
)

add_executable(prog1 ${SRC})

target_link_libraries(prog1 lib1)

IF (NOT WIN32)
  target_link_libraries(prog1 m)
ENDIF()
