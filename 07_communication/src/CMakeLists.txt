add_executable(main main.cpp)

# 设置target进行include的目录
target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR})