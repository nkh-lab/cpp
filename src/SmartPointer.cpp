#include <memory>

#include "clsA.hpp"

namespace SmartPointer {

void test(void)
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
    // ! plain pointer 'pA' didn't destroy its object but smart 'upA' did
}

}
