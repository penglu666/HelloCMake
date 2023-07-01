cmake_minimum_required(VERSION 3.0)
project(12_cmake_build_type C CXX) 

# 设置cmake的编译类型
set(CMAKE_BUILD_TYPE release CACHE STRING "build type" FORCE)
if(CMAKE_BUILD_TYPE EQUAL "debug")
    message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
else()
    message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
endif()

message(STATUS "This is src directory " ${CMAKE_SOURCE_DIR})
message(STATUS "This is binary directory " ${CMAKE_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
# 1. 设置库存放的地址（第一种方式）
# set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
# 2. 设置库存放的地址（第二种方式）

# 设置生成动态库还是静态库
option(BUILD_SHARED_LIBS "generate shared libs?" OFF)

if(BUILD_SHARED_LIBS)
    message(STATUS "use shared libs")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib") # .so的地址
else()
    message(STATUS "use static libs")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib") # .so的地址
endif()

configure_file(config.h.in config.h)

option(USE_THIRDPARTY "use thirdparty library" ON)

# 使用if-endif语句来决定是否使用第三方库
if(USE_THIRDPARTY)
    message(STATUS "USE_THIRDPARTY")
    add_subdirectory(thirdparty)
    # EXTRA_LIBS: 将库文件名称最佳到EXTRA_LIBS列表中
    list(APPEND EXTRA_LIBS myadd)
    message(STATUS "EXTRA_LIBS = " "${EXTRA_LIBS}")
endif()

add_subdirectory(src)