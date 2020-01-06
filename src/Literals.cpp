#include "Literals.hpp"

#include <cstring>
#include <cassert>
#include <iostream>

namespace Literals {

/*
 * User defined run-time binary literal
 *
 * Since C++11
 */
size_t operator""_brt(const char* s)
{
    size_t numBits = std::strlen(s);
    size_t value{0};

    for(size_t i = 0; i < numBits; ++i)
    {
        const char& c = s[numBits - 1 - i];

        assert ((c == '1' || c == '0'));

        if(c == '1') value += 1 << i;
    }

    return value;
}

/*
 * User defined compile-time binary literal
 *
 * Since C++14
 */
template<char... bits>
class Binary;

template<char high_bit, char... bits>
class Binary<high_bit, bits...>
{
    static constexpr auto numBits = sizeof... (bits);
public:
    static constexpr size_t value = (high_bit - '0') << numBits | Binary<bits...>::value;
};

template<char high_bit>
class Binary<high_bit>
{
public:
    static constexpr size_t value = (high_bit - '0');
};

template<char... bits>
constexpr unsigned int operator""_bct()
{
    return Binary<bits...>::value;
}

void test(void)
{
    // User defined run-time binary literal
    std::cout << 110_brt << std::endl;

    // User defined compile-time binary literal
    std::cout << 110_bct << std::endl;
}

}
