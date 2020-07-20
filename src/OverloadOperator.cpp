#include "OverloadOperator.hpp"
#include <iostream>

namespace OverloadOperator {

void test(void)
{
    A a;

    a << 1 << 2 << 3 << "www" << 2.5 << "\n";

    /* output:

    123www2.5

     */
}

} // namespace OverloadOperator
