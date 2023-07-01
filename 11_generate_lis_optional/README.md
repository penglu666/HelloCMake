# 11_generate_lis_optional
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 11_generate_lis_optional
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

在上一小节中介绍了给动态库设置一些依赖，比如是否对第三方库进行编译、设置静态库的名称、动态库的版本
在这一小节中，我们还可以设置库的存放地址、生成动态库还是静态库，
1. 设置libs的存放地址
    主要有两种方式：
(1) 使用LIBRARY_OUTPUT_PATH设置库存放的地址
```cmake
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
```
(2) 使用CMAKE_LIBRARY_OUTPUT_DIRECTORY设置libs存放的地址
```cmake
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") 
```
与CMAKE_LIBRARY_OUTPUT_DIRECTORY相似的还有两个变量
```cmake
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib") # .a .lib静态库的地址
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib") # .so动态库的地址
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib") # .dll .exe windows动态库和可执行程序的地址或只有linux的可执行文件，没有动态库文件
```

2. 设置生成动态库还是静态库
```cmake
option(BUILD_SHARED_LIBS "generate shared libs?" OFF)
```
我们通过设置BUILD_SHARED_LIBS来控制生成动态库还会静态库(BUILD_SHARED_LIBS是一个全局变量)
```cmake
if(BUILD_SHARED_LIBS)   # 设置动态库
    add_library(myadd SHARED myadd.cpp myadd.hpp)
    set_target_properties(myadd PROPERTIES VERSION 1.0 SOVERSION 1.0)
    target_include_directories(myadd INTERFACE "${PROJECT_CURRENT_SOURCE_DIR}")
else()  # 设置静态库
    add_library(myadd STATIC myadd.cpp myadd.hpp)
    target_include_directories(myadd INTERFACE "${PROJECT_CURRENT_SOURCE_DIR}")
endif()
```