#include <stdio.h>
#include <iostream>

#include "manipulators.hpp"
#include "clsA.hpp"
#include "functor.hpp"


int main(void)
{
    printf("Hello World!\n");

    //manipulators();
    //testFunctor();

    // different cases to init objects
    clsA a0((char*)"A0 object");
    clsA a1 {(char*)"A1 object"};

    return 0;
}


