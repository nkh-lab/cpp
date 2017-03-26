#include <iostream>

#include "clsA.hpp"


clsA::clsA(char* name):Name(name)
{
    std::cout << "clsA constructor for Name = " << Name << std::endl;
}

void clsA::printName()
{
    std::cout << Name << std::endl;
}

