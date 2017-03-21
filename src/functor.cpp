#include <iostream>

#include "functor.hpp"

class clsSimpleFunctor
{
    char* Name;

public:
    clsSimpleFunctor(char* name): Name(name) {}

    void operator()()
    {
        std::cout << Name << std::endl;
    }
};


void testFunctor()
{
    clsSimpleFunctor functor((char*)"My functor");

    functor();

    clsSimpleFunctor((char*)"www")();
}
