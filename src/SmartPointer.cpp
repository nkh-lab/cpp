#include <memory>

#include "clsA.hpp"

namespace SmartPointer {

void test(void)
{
    clsA a((char*)"A");

    std::unique_ptr<clsA> upA(new clsA((char*)"A through unique_ptr"));
}

}
