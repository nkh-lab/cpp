#include <iostream>
#include <limits>
#include <limits.h>
#include "Basic.hpp"

namespace Basic {

void test(void)
{
    int nums[5] = {1, 2, 3, 4, 5};

    // foreach
    for(int i: nums)
    {
        std::cout << i << std::endl;
    }

    /* Numeric Limits: */

    std::cout << "C style (#include <limits.h>):" << std::endl;
    std::cout << "  int MAX = " << INT_MAX << std::endl;
    std::cout << "u_int MAX = " << UINT_MAX << std::endl;

    std::cout << "C++ style (#include <limits>):" << std::endl;
    std::cout << "  int MAX = " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "u_int MAX = " << std::numeric_limits<unsigned int>::max() << std::endl;
}

}

