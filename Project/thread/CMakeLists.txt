cmake_minimum_required (VERSION 3.9)

project(thread_example)

set(CMAKE_CXX_STANDARD 17)

set(SRCS "thread_example.cpp" "some_defines.cpp")

add_executable (thread_example ${SRCS})

find_package (Threads)

target_link_libraries (thread_example Threads::Threads)

install(TARGETS thread_example RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../bin)
