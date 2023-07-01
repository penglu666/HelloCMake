#include <iostream>
#include <math.h>
#include "config.h"

int main(){

    std::cout << "welcome to cmake world" << std::endl;
#ifdef USE_THIRDPARTY:
    #include "myadd.hpp"
    std::cout << "use my add = " << myAdd(1.0, 3.0) << std::endl;
#else
    std::cout << "use  standard= " << (1+2) << std::endl;
#endif
    return 0;
}