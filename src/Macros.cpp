#include "Macros.hpp"
#include <iostream>
#include <stdio.h>

namespace Macros {

bool check(bool b)
{
    if (b) std::cout << "b == true " << std::endl;
    else   std::cout << "b == false" << std::endl;

    return b;
}

#define M(b) std::cout << "Comma in macro" << std::endl, check(b)


void test(void)
{
    if (M(true)) std::cout << "M == true " << std::endl;
    else         std::cout << "M == false" << std::endl;

    /* Cout:

    Comma in macro
    b == true
    M == true

     */
}

}
