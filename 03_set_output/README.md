# 03_set_output
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 03_set_output
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了
在02_multilevel的可执行程序是放在build/src文件夹下的，如果我们需要指定可执行程序的存放位置，我们可以在CMakeLists.txt中添加这个指令：
```bash
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
```
其中的EXECUTABLE_OUTPUT_PATH就是设定存放可执行程序的变量，默认是在哪里编译的，就存放到哪里
