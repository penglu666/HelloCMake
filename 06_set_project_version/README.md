# 06_set_project_version
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 06_set_project_version
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

1. 设置cpp的版本(11, 14, 17等)
```bash
# 设置cpp的版本
set(CMAKE_CXX_STANDARD 11)
# 系统支持的cpp版本是否一定为11，如果为True，但是系统不支持就会报错
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
2. 在源程序中打印cpp的版本号
```
std::cout << __cplusplus << std::endl;
```