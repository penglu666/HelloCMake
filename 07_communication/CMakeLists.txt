cmake_minimum_required(VERSION 3.0)
project(07_communication VERSION 1.0 LANGUAGES C CXX) 

message(STATUS "This is src directory " ${PROJECT_SOURCE_DIR})
message(STATUS "This is binary directory " ${PROJECT_BINARY_DIR})


# 打印项目的版本号
message(STATUS "major version: ${PROJECT_VERSION_MAJOR}")
message(STATUS "minor version: ${PROJECT_VERSION_MINOR}")

# 设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 读取config.in.h文件，将结果保存到config.h文件中
configure_file(config.h.in config.h)

# 设置cpp的版本
set(CMAKE_CXX_STANDARD 11)
# 系统支持的cpp版本是否一定为11，如果为True，但是系统不支持就会报错
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)