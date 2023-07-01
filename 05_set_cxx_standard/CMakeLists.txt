cmake_minimum_required(VERSION 3.0)
project(05_set_cxx_standard C CXX) 

message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 设置cpp的版本
set(CMAKE_CXX_STANDARD 11)
# 系统支持的cpp版本是否一定为11，如果为True，但是系统不支持就会报错
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)