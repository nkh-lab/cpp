#include <string>
#include <iostream>
#include "Str.hpp"

namespace Str {

void test_snprintf();
std::string convertMacBytesToString(const unsigned char (&bytes) [6]);

void test(void)
{
    test_snprintf();


    unsigned char mac[6] = {0xde, 0xad, 0xbe, 0xef, 0x20, 0x17};

    std::cout << convertMacBytesToString(mac) << std::endl;

    /* output:

    de:ad:be:ef:20:17

    */
}

void test_snprintf()
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

std::string convertMacBytesToString(const unsigned char (&bytes) [6])
{
    char buf1[18] = {0}; // 17 + /n

    std::snprintf(buf1, 18, "%02x:%02x:%02x:%02x:%02x:%02x", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5]);//

    return std::string(buf1);
}

}
