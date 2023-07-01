cmake_minimum_required(VERSION 3.0)
project(08_use_libs C CXX) 

message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

# 每个需要管理的文件都需要一个cmakelists.txt文件
add_subdirectory(thirdparty)
add_subdirectory(src)