#include <iostream>

#include "clsA.hpp"


clsA::clsA(char* name):Name(name)
{

}

void clsA::printName()
{
    std::cout << Name << std::endl;
}

