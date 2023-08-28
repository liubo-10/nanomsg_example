cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

project(nanomsg_main)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    /home/edy/my_project/nanomsg/nanomsg-1.2/src   
    /usr/local/include/nanomsg
    )

 
# Find requirements
set(nanomsg_DIR /home/edy/my_project/nanomsg/nano_install/lib)


find_package(nanomsg CONFIG REQUIRED)



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


message(STATUS "Configuring nanomsg_main publisher/subscriber example...")



add_executable(nanomsg_main  src/nanomsg_main.cpp    src/nanomsg_publisher.cpp  src/nanomsg_subscriber.cpp)
target_link_libraries(nanomsg_main nanomsg)


