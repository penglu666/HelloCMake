cmake_minimum_required(VERSION 3.0)
project(09_use_libs_optional C CXX) 

message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

configure_file(config.h.in config.h)

option(USE_THIRDPARTY "use thirdparty library" ON)

# 使用if-endif语句来决定是否使用第三方库
if(USE_THIRDPARTY)
    message(STATUS "USE_THIRDPARTY")
    add_subdirectory(thirdparty)
    # EXTRA_INCLUDES: 将头文件路径地址追加到EXTRA_INCLUDES列表中
    # EXTRA_LIBS: 将库文件名称最佳到EXTRA_LIBS列表中
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/thirdparty")
    list(APPEND EXTRA_LIBS myadd)
endif()

add_subdirectory(src)