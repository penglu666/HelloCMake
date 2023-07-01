# 08_use_libs
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 08_use_libs
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

上文提供了生成链接库的样例，在这部分主要是介绍如何使用动态库
1. 在链接库目录下添加hpp和cpp文件以及一个单独的cmakelists.txt文件
```bash
add_library(myadd SHARED myadd.cpp myadd.hpp)
set_target_properties(myadd PROPERTIES VERSION 1.0 SOVERSION 1.0)
```
2. 在主cmakelists.txt文件中添加链接库作为子编译文件夹
```
add_subdirectory(thirdparty)
```
3. 在src文件夹下添加可执行文件的头文件搜索路径以及将动态库链接给可执行文件
```
add_executable(main main.cpp)
# 添加头文件的搜索路径(注意PUBLIC)
target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/thirdparty")
# 添加可执行文件所依赖的动态链接库
target_link_libraries(main PUBLIC myadd)
```
4. 在cpp源文件中引入第三方库的头文件
```c++
#include "myadd.hpp"
```
此时就可以使用第三方库中的文件了

