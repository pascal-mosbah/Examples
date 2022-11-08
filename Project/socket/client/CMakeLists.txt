cmake_minimum_required (VERSION 3.9)

project(socket_example_client)


set(SRCS "socket_example_client.cpp" "../../thread/some_defines.cpp")

add_executable (socket_example_client ${SRCS})
include_directories(../../thread)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

IF(MSVC)
	SET(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../../boost_1_77_0")
ENDIF()

find_package(Boost 1.77 REQUIRED COMPONENTS system thread regex serialization)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  target_link_directories(socket_example_client PUBLIC ${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

target_compile_features(socket_example_client PUBLIC cxx_std_17)
target_link_libraries (socket_example_client PUBLIC  ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY} ${Boost_SERIALIZATION_LIBRARY})
install(TARGETS socket_example_client RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../../bin)
