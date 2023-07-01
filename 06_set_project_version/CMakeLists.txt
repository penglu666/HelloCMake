cmake_minimum_required(VERSION 3.0)
# 通过VERSION设置项目的版本
# 通过LANGUAGES设置项目使用到的语言(可不设置)
project(06_set_cxx_standard VERSION 1.0 LANGUAGES C CXX) 

message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})
# project_source_dir和cmake_source_dir是等价的
message(STATUS "This is src directory " ${PROJECT_SOURCE_DIR})
message(STATUS "This is binary directory " ${PROJECT_BINARY_DIR})

# 打印项目的版本号
message(STATUS "major version: ${PROJECT_VERSION_MAJOR}")
message(STATUS "minor version: ${PROJECT_VERSION_MINOR}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 设置cpp的版本
set(CMAKE_CXX_STANDARD 11)
# 系统支持的cpp版本是否一定为11，如果为True，但是系统不支持就会报错
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)