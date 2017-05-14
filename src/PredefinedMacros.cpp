#include <iostream>

#include "PredefinedMacros.hpp"

namespace PredefinedMacros {

void test(void)
{
    std::cout << __FUNCTION__ << "() in file " << __FILE__ << " on line " << __LINE__ << "\n";

    /* output:

    test() in file /home/nkh/my/cpp/src/PredefinedMacros.cpp on line 9

    */

    std::cout << __PRETTY_FUNCTION__ << std::endl;

    /* output:

    void PredefinedMacros::test()

    */
}

}
