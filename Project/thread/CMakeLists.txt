cmake_minimum_required (VERSION 3.9)

project(thread_example)


set(SRCS "thread_example.cpp" "some_defines.cpp")

add_executable (thread_example ${SRCS})

find_package (Threads)

target_compile_features(thread_example PUBLIC cxx_std_17)
target_link_libraries (thread_example Threads::Threads)

install(TARGETS thread_example RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../bin)
