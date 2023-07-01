add_executable(main main.cpp)

# 添加头文件的搜索路径
target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/thirdparty")
# 添加可执行文件所依赖的动态链接库
target_link_libraries(main PUBLIC myadd)
