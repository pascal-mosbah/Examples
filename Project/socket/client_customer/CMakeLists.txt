# cmake_minimum_required(VERSION 3.20)

# project(client_server_customer)

# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_USE_RELEASE_LIBS ON)

# if(MSVC)
# 	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
#     set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#     set(Boost_USE_STATIC_RUNTIME ON)
# 	set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")
# elseif(MSVC)
#     set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
# endif (MSVC)

# find_package(Boost 1.80.0 COMPONENTS json REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})

# set(client_server_customer_src client_server_customer.cpp)
# add_executable(client_server_customer ${client_server_customer_src})
# target_link_libraries (client_server_customer LINK_PUBLIC customer)