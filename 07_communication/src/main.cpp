#include <iostream>
#include "config.h"

int main(){
    std::cout << __func__ << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "welcome to cmake world" << std::endl;
    std::cout << "current cpp standard: " << __cplusplus << std::endl;
    std::cout << "project version major" << PROJECT_VERSION_MAJOR << std::endl;
    std::cout << "project version minor" << PROJECT_VERSION_MINOR << std::endl;

    return 0;
}