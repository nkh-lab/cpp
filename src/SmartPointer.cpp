#include "SmartPointer.hpp"
#include <memory>
#include "clsA.hpp"

namespace SmartPointer {

void test_constructors(void);
void test_uptr(void);

void test(void)
{
    // test_constructors();
    test_uptr();
}

void test_constructors(void)
{
    // constructor with managed object
    {
        clsA a((char*)"A");
        clsA* pA = new clsA((char*)"pA");

        if (pA != nullptr)
            ; // to suppress warning: unused variable ‘pA’ [-Wunused-variable]

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

    if (upANoM == nullptr)
    {
        upANoM->testInline();
    }

    /* output:

    clsA testInline()

    */
    // ! No constructor and destructor call but method could be called
    // but not members, e.g. upANoM->I
}

typedef std::unique_ptr<int> upiType;

void test_uptr_copy(upiType p)
{
    std::cout << "*p = " << *p << std::endl;
}

void test_uptr_ref(const upiType& p)
{
    std::cout << "*p = " << *p << std::endl;
}

void test_uptr(void)
{
    std::unique_ptr<int> up1(new int(111));
    std::unique_ptr<int> up2;

    up2 = std::unique_ptr<int>(new int(222));

    std::cout << "*up1 = " << *up1 << std::endl;
    std::cout << "*up2 = " << *up2 << std::endl;

    test_uptr_ref(up1);
    std::cout << "*up1 = " << *up1 << std::endl;

    /* ! Not allowed !
    test_uptr_copy(up1);
    */
}

} // namespace SmartPointer
