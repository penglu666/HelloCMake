# 09_use_libs_optional
这一小节介绍如何使用cmake对cpp工程进行编译
```bash
    cd 09_use_libs_optional
    sh 0_run_build.sh
```
运行的运行效果如下：
![](images/01_build_result.png)
当屏幕上打印"welcom to cmake world"的时候，就说明程序已经正确编译并运行了

上文介绍了如何编译库文件，本文介绍一下如何可选的对库文件进行链接
1. 在cmakelists.txt文件中使用option创建变量
```cmake
option(USE_THIRDPARTY "use thirdparty library" ON)
```
2. 将变量使用config_file()函数传递给cpp源文件
```cmake
configure_file(config.h.in config.h)
```
4. 使用cmakedefin在config.h.in中进行定义
```cmake
#cmakedefine USE_THIRDPARTY
```
5. 创建库列表和头文件列表保存需要链接的库文件和头文件，并可选的进行链接和引用
```cmake
# 使用if-endif语句来决定是否使用第三方库
if(USE_THIRDPARTY)
    message(STATUS "USE_THIRDPARTY")
    add_subdirectory(thirdparty)
    # EXTRA_INCLUDES: 将头文件路径地址追加到EXTRA_INCLUDES列表中
    # EXTRA_LIBS: 将库文件名称最佳到EXTRA_LIBS列表中
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/thirdparty")
    list(APPEND EXTRA_LIBS myadd)
endif()

# 添加头文件的搜索路径
target_include_directories(main PUBLIC 
                            "${EXTRA_INCLUDES}"
                            "${PROJECT_BINARY_DIR}"
                            )

# 添加可执行文件所依赖的动态链接库
target_link_libraries(main PUBLIC "${EXTRA_LIBS}")
```
6. 在src/main.cpp文件中使用变量可选的对库函数进行使用
```cpp
#ifdef USE_THIRDPARTY:
    #include "myadd.hpp"
    std::cout << "use my add = " << myAdd(1.0, 3.0) << std::endl;
#else
    std::cout << "use  standard= " << (1+2) << std::endl;
#endif
```
7. 在0_run_build.sh脚本中设置定义变量的值
```bash
mkdir -p build
cd build && cmake .. -DUSE_THIRDPARTY=ON && make -j8
cd .. && ./bin/main
```
将-DUSE_THIRDPARTY设置为OFF之后，就表示不使用这个变量
