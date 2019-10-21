#include "Literals.h"

#include <cstring>
#include <cassert>
#include <iostream>

namespace Literals {

/*
 * Binary literal
 *
 * User defined literal. Run-time execution.
 */

unsigned long long operator""_b(const char* s)
{
    size_t size = std::strlen(s);
    unsigned long long v{0};

    for(size_t i = 0; i < size; ++i)
    {
        const char& c = s[size - 1 - i];

        assert ((c == '1' || c == '0'));

        if(c == '1') v += 1 << i;
    }

    return v;
}

void test(void)
{
    // Binary literal
    std::cout << 110_b << std::endl;
}

}