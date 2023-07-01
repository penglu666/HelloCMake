# 05_set_cxx_standard
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 05_set_cxx_standard
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

## cmakelists.txt和cpp进行信息交互
比如我们在cmakelists.txt文件中设置了版本号，我们想在cpp源程序代码中使用，主要有以下几个步骤

1. 定义config.h.in文件中的变量
```
#define PROJECT_VERSION_MAJOR ${PROJECT_VERSION_MAJOR}
#define PROJECT_VERSION_MINOR ${PROJECT_VERSION_MINOR}

```
2. 在cmakelists.txt中加载config.h.in文件，并输出到config.h文件中
```
# 读取config.in.h文件，将结果保存到config.h文件中
configure_file(config.h.in config.h)
```

3. 设置可执行文件头文件的搜索地址
```
# 设置target进行include的目录:
#   main就是我们的target(可执行文件)
#   ${PROJECT_BINARY_DIR}就是build的地址，config.h会保存到build目录下，因此需要include
target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR})
```

4. 进行cmake
cmake之后，会在build文件夹下生成config.h文件，其内容就是多个宏变量
```
#define PROJECT_VERSION_MAJOR 1
#define PROJECT_VERSION_MINOR 0
```

5. 在源程序代码中使用config.h中的宏定义变量
```
#include "config.h"
std::cout << "project version major" << PROJECT_VERSION_MAJOR << std::endl;
std::cout << "project version minor" << PROJECT_VERSION_MINOR << std::endl;
```