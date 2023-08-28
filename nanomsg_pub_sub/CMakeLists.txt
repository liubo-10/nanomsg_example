cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

project(nanomsg_test)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    
# Find requirements
set(nanomsg_DIR /home/edy/my_project/nanomsg/nano_install/lib)

if(NOT nanomsg_FOUND)
find_package(nanomsg CONFIG REQUIRED)
endif()



# Set C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR
        CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    check_cxx_compiler_flag(-std=c++11 SUPPORTS_CXX11)
    if(SUPPORTS_CXX11)
        add_compile_options(-std=c++11)
    else()
        message(FATAL_ERROR "Compiler doesn't support C++11")
    endif()
endif()


message(STATUS "Configuring nanomsg_test publisher/subscriber example...")



add_executable(nanomsg_test src/nanomsg_pub.cpp)



