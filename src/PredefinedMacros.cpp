#include <iostream>

#include "PredefinedMacros.hpp"

namespace PredefinedMacros {

void test(void)
{
    std::cout << __FUNCTION__ << "() in file " << __FILE__ << " on line " << __LINE__ << "\n";
}

}
