# 04_generate_libs
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 04_generate_libs
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

1. 生成动态库和静态库
这一部分我们是使用cmake对源码进行编译，从而得到动态库或者静态链接库；
```
add_library(main_static STATIC main.cpp)
add_library(main SHARED main.cpp)
```
上面第一行表示生成main_static静态库的名字，main表示生成动态库的名字，
2. 修改存放库的文件地址
生成库存放的地方默认是在哪里编译，就存放到哪里，我们可通过设置
LIBRARY_OUTPUT_PATH来设置生成的库的存放的地址：
```
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
```

3. 修改动态库和静态库的属性
3.1 修改静态库的名字
```
set_target_properties(main_static PROPERTIES OUTPUT_NAME "main")
```
由于生成的静态库的名字是main_static，我们需要将其修改为main，所以可以调用
set_target_properties来进行设定
3.2 修改动态库的版本号
我们同样可以使用set_target_properties来设置动态链接库的版本号
```
set_target_properties(main PROPERTIES VERSION 1.1 SOVERSION 1)
```
其中的VERSION表示动态库的版本号，SOVERSION表示api的版本号
![](images/04_libs.png)
