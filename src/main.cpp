#include <stdio.h>
#include <iostream>

#include "Basic.hpp"
#include "PredefinedMacros.hpp"
#include "manipulators.hpp"
#include "clsA.hpp"
#include "functor.hpp"
#include "initialyzerlist.hpp"
#include "virtualdestructor.hpp"
#include "SmartPointer.hpp"
#include "CopyMoveCtor.hpp"
#include "IO.hpp"
#include "VectorVsList.hpp"
#include "OverloadOperator.hpp"


int main(void)
{
    printf("Hello World!\n");

#if 0
    // different cases to init objects
    clsA a0((char*)"A0 object");
    clsA a1 {(char*)"A1 object"};
    clsA* a2 = new  clsA ((char*)"A2 object");
    clsA* a3 = new  clsA {(char*)"A3 object"};

    a3->testInline();

    delete a2;
    delete a3;
#endif

    //Basic::test();

    PredefinedMacros::test();

    //manipulators();
    //testFunctor();
    //initialyzerlist();
    //virtualdestructor::test();
    //SmartPointer::test();
    //CopyMoveCtor::test();
    //IO::test();
    //VectorVsList::test();
    //OverloadOperator::test();

    return 0;
}


