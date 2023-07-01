if(BUILD_SHARED_LIBS)   # 设置动态库
    add_library(myadd SHARED myadd.cpp myadd.hpp)
    set_target_properties(myadd PROPERTIES VERSION 1.0 SOVERSION 1.0)
    target_include_directories(myadd INTERFACE "${PROJECT_CURRENT_SOURCE_DIR}")
else()  # 设置静态库
    add_library(myadd STATIC myadd.cpp myadd.hpp)
    target_include_directories(myadd INTERFACE "${PROJECT_CURRENT_SOURCE_DIR}")
endif()