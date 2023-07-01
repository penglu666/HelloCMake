cmake_minimum_required(VERSION 3.0)
project(03_set_executable_output C CXX) 

message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})

# 设置存放可执行文件的地址
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 每个需要管理的文件都需要一个cmakelists.txt文件
# 使用add_subdirectory之后，cmake会自动对src下的文件进行编译
add_subdirectory(src)