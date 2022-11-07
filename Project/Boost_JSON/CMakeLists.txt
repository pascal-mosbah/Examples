cmake_minimum_required(VERSION 3.20)

project(json)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(Boost_USE_STATIC_RUNTIME ON)
	set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")
elseif(MSVC)
    set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(Boost 1.80.0 COMPONENTS json REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(read_json_src read_json.cpp)
add_executable(read_json ${read_json_src})

set(write_json_src write_json.cpp)
add_executable(write_json ${write_json_src})
