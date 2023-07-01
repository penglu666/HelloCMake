# 生成的静态库和动态库的名称是不一样的
add_library(main_static STATIC main.cpp)
# 设置静态库的名称，这样静态库和动态库的名称就一样了
set_target_properties(main_static PROPERTIES OUTPUT_NAME "main")
# 还可以设置动态库的版本号
add_library(main SHARED main.cpp)
set_target_properties(main PROPERTIES VERSION 1.1 SOVERSION 1)