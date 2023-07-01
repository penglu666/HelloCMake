# 12_cmake_build_type
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 12_cmake_build_type
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

在本章节中主要介绍一下如何设置cmake的编译版本
1. 通过cmake进行设置
```bash
cmake .. -DUSE_THIRDPARTY=ON -DCMAKE_BUILD_TYPE="release"&& make -j8
```
通过设置CMAKE_BUILD_TYPE的值为release或者是debug来设置类型
2. 在cmakelists.txt中设置变量
```cmake
# 设置cmake的编译类型
set(CMAKE_BUILD_TYPE debug CACHE STRING "build type" FORCE)
if(CMAKE_BUILD_TYPE EQUAL "debug")
    message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
else()
    message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
endif()
```
其中的CACHE表示变量的标志，STRING表示变量为字符串类型的；FORCE表示强制转换成CACHE对应的类型
即强制转换成字符串类型