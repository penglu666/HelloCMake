#include <iostream>

int main(){
    std::cout << __func__ << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "welcome to cmake world" << std::endl;
    std::cout << "current cpp standard: " << __cplusplus << std::endl;
    return 0;
}