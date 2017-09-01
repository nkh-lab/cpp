#include <iostream>

#include "clsA.hpp"

clsA::clsA()
{
    std::cout << "clsA constructor without Name" << std::endl;
}

clsA::clsA(char* name):Name(name)
{
    std::cout << "clsA constructor for Name = " << Name << std::endl;
}

void clsA::printName()
{
    std::cout << Name << std::endl;
}

