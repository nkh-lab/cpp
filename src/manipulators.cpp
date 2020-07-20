#include "manipulators.hpp"

#include <iomanip> // std::setbase
#include <ios>
#include <iostream>

void manipulators(void)
{
    int test = 15;

    std::cout.setf(std::ios::showbase); // 0x for hex and 0 for oct

    std::cout << test << std::endl;

    std::cout << std::hex;

    std::cout << test << std::endl;

    std::cout << std::setbase(10);

    std::cout << test << std::endl;
}
