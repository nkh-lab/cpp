#include <iostream>
#include <functional>

#include "Function.hpp"

namespace Function {

void test(void)
{
    std::function<void()> f1 = [] (){std::cout << "Hello from target1" << std::endl;};

    if(f1 == nullptr) std::cout << "f1 = nullptr" << std::endl;
    else std::cout << "f1 = not nullptr" << std::endl;

    f1();

    f1 = nullptr;

    if(f1 == nullptr) std::cout << "f1 = nullptr" << std::endl;
    else std::cout << "f1 = not nullptr" << std::endl;

    //f1(); // - comment out to avoid crash

    /* Output:

    Hello World!
    f1 = not nullptr
    Hello from target1
    f1 = nullptr
    terminate called after throwing an instance of 'std::bad_function_call'
      what():  bad_function_call
    The program has unexpectedly finished.
    /.../cpp crashed.

    */
}

}
