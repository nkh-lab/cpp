#include <memory>

#include "clsA.hpp"

namespace SmartPointer {

void test(void)
{
    // constructor with managed object
    {
        clsA a((char*)"A");
        clsA* pA = new clsA((char*)"pA");

        if(pA != nullptr);// to suppress warning: unused variable ‘pA’ [-Wunused-variable]


        std::unique_ptr<clsA> upA(new clsA((char*)"upA"));

        /* output:
        clsA constructor for Name = A
        clsA constructor for Name = pA
        clsA constructor for Name = upA
        clsA destructor  for Name = upA
        clsA destructor  for Name = A
        */
        // ! Object pointed by play pointer 'pA' was not destroyed
    }


    // constructor with no managed object
    std::unique_ptr<clsA> upANoM;

    if(upANoM == nullptr)
    {
        upANoM->testInline();
    }

    /* output:

    clsA testInline()

    */
    // ! No constructor and destructor call but method could be called
    // but not members, e.g. upANoM->I
}

}
