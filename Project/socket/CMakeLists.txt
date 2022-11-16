cmake_minimum_required(VERSION 3.20)

project(socket_example)

set (CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(Boost_USE_STATIC_RUNTIME ON)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
    set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")
elseif(MSVC)
    set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(Boost 1.80.0 COMPONENTS system thread regex serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS} ../thread)
link_directories(${Boost_LIBRARY_DIRS})

set(server_src server/socket_example_server.cpp "../thread/some_defines.cpp")
add_executable(server ${server_src})
set_property(TARGET server PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
target_link_libraries(server LINK_PUBLIC ${Boost_LIBRARIES})

set(client_src client/socket_example_client.cpp "../thread/some_defines.cpp")
add_executable(client ${client_src})
set_property(TARGET client PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
target_link_libraries(client LINK_PUBLIC ${Boost_LIBRARIES})


set(run_client_instances_src run_client_instances/run_client_instances.cpp "../thread/some_defines.cpp")
add_executable(run_client_instances ${run_client_instances_src})
target_link_libraries(run_client_instances LINK_PUBLIC ${Boost_LIBRARIES})
set_property(TARGET run_client_instances PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# set(server_customer_src client_customer/server_customer.cpp client_customer/send_receive.cpp)
# add_executable(server_customer ${server_customer_src})
# target_link_libraries (server_customer LINK_PUBLIC customer ${Boost_LIBRARIES})

# set(client_customer_src client_customer/client_customer.cpp client_customer/send_receive.cpp)
# add_executable(client_customer ${client_customer_src})
# target_link_libraries (client_customer LINK_PUBLIC customer ${Boost_LIBRARIES})

# set(test_socket_server_src test_socket/blocking_tcp_echo_server.cpp)
# add_executable(blocking_tcp_echo_server ${test_socket_server_src})
# target_link_libraries (blocking_tcp_echo_server LINK_PUBLIC customer ${Boost_LIBRARIES})

# set(test_socket_client_src test_socket/blocking_tcp_echo_client.cpp)
# add_executable(blocking_tcp_echo_client ${test_socket_client_src})
# target_link_libraries (blocking_tcp_echo_client LINK_PUBLIC customer ${Boost_LIBRARIES})
