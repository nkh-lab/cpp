#include <string>
#include <iostream>
#include "Str.hpp"

namespace Str {

void test(void)
{
    // string format

    int num = 12345;
    char buf[4] = {0};

    std::snprintf(buf, 4, "%03d", num);// 4 - we need only 3 digits ( + /n) v.000

    std::string s = "v." + std::string(buf);

    std::cout << s << std::endl;

    /* cout

     v.123

     */
}

}
