#ifndef CLSA_HPP
#define CLSA_HPP

#include <iostream>

class clsA
{
    char* Name;

public:
    clsA();
    clsA(char* name);

    ~clsA() { std::cout << "clsA destructor  for Name = " << Name << std::endl; }

    void printName();

    inline void testInline(void) { std::cout << "clsA testInline()" << std::endl; }

    int I = 123;
};

#endif
