# 设置cmake的版本
cmake_minimum_required(VERSION 3.0)
# 设置项目工程名称, C CXX表示项目所用到的语言
project(01_single_level C CXX) 

# message用于打印信息，STATUS表示在打印信息的前添加--
# ${CMAKE_SOURCE_DIR}:表示项目工程的路径，即HelloCMake/01_hello_cmake的地址
message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
# ${CMAKE_BINARY_DIR}:表示build的地址，即HelloCMake/01_hello_cmake/build的地址
# 在哪里调用进行cmake的，就是那里的地址
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})

# 生成可执行文件
add_executable(main main.cpp)