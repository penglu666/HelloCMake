add_executable(main main.cpp)

target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}")

# 添加可执行文件所依赖的动态链接库
target_link_libraries(main PUBLIC "${EXTRA_LIBS}")

