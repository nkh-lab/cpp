#include "Tricks.hpp"
#include "clsA.hpp"

namespace Tricks {

/*
 * Calling non static method without class instantiation.
 */
void test_call_nonstatic_method(void)
{
#define ANY_MEM_ADR 0x00

    clsA* a = (clsA*)ANY_MEM_ADR;

    a->testInline();
}

void test(void)
{
    test_call_nonstatic_method();
}

} // namespace Tricks
