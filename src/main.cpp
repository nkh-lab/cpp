#include <stdio.h>
#include <iostream>
#include "main.hpp"

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

    //PredefinedMacros::test();

    //manipulators();
    //testFunctor();
    //initialyzerlist();
    //virtualdestructor::test();
    //SmartPointer::test();
    //WeakPointer::test();
    //CopyMoveCtor::test();
    //IO::test();
    //VectorVsList::test();
    //OverloadOperator::test();
    //Macros::test();
    //Containers::test();
    //Tricks::test();
    //Promise::test();
    //Function::test();
    //Str::test();
    //UID::test();
    //Literals::test();
    //SyncQueue::test();
    //MyForwardList::test();
    Runnable::test();

    return 0;
}


