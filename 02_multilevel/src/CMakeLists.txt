add_library(main_shared SHARED main.cpp)
add_library(main_static STATIC main.cpp)
add_executable(main main.cpp)