cmake_minimum_required (VERSION 3.9)

project(run_client_instances)


set(SRCS "run_client_instances.cpp")

add_executable (run_client_instances ${SRCS})


install(TARGETS run_client_instances RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../../bin)
