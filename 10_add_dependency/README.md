# 10_add_dependency
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 10_add_dependency
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

上一节中可选择的对库文件进行了编译和使用，但是还是存在了冗余的情况，比如我们main可执行文件
使用myadd库的时候还需要添加该库的头文件，这样比较麻烦。我们可以使得该库在编译的时候就将头文件
也一同编译
1. 使用target_include_directories()对库文件添加头文件
```cmake
target_include_directories(myadd INTERFACE "${PROJECT_CURRENT_SOURCE_DIR}")
```
(1) INTERFACE:  当前的库文件不可见，但是依赖该库的库可见
(2) PUBLIC:     当前的库文件可见，依赖该库的库也可见
(3) PRIVATE:    当前的库可见，依赖该库的库不可见
