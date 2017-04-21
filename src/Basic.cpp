#include <iostream>

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
}

}

