#include <stdio.h>
#include <iostream>

#include "manipulators.hpp"
#include "clsA.hpp"
#include "functor.hpp"
#include "initialyzerlist.hpp"


int main(void)
{
    printf("Hello World!\n");

    //manipulators();
    //testFunctor();

    // different cases to init objects
    clsA a0((char*)"A0 object");
    clsA a1 {(char*)"A1 object"};
    clsA* a2 = new  clsA ((char*)"A2 object");
    clsA* a3 = new  clsA {(char*)"A3 object"};

    a3->testInline();

    delete a2;
    delete a3;

    initialyzerlist();

    return 0;
}


