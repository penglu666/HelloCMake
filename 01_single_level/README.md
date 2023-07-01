# 01_single_level
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 01_single_level
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了
CMakeLists.txt的主要函数：
(1) cmake_minimum_required: 指定cmake的版本
(2) project: 设置项目的名称，后续可指定项目所使用的编写语言，比如c和cpp
(3) message: 在编译过程中打印在终端上的提示信息，STATUS变量表示会在打印细心耐心之前添加两个-
(4) add_executable: 生成可执行文件，第一个参数表示可执行文件的名称，第二个参数表示由哪些文件构建得到可执行文件

