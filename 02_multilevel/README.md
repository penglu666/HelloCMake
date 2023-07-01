# 02_multilevel
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 02_multilevel
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了
在大型项目的编写过程中，我们通常会将所有的源文件都放到src文件夹下，并将src下的文件编译为可执行文件。这就需要在src下也新增一个CMakeLists.txt文件，并在外层的CMakeLists.txt文件也指定src的位置
(1) add_subdirectory(src):这个函数的作用就是告诉cmake，src文件夹下还有一个CMakeLists.txt，你需要单独对src文件夹进行编译，并将其的编译结果也放到build下的src文件夹中。
