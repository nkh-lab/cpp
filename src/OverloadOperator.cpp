#include <iostream>
#include "OverloadOperator.hpp"


namespace OverloadOperator {

class A
{
    int storage;

public:
    // overload operator with Template parameter
    template<typename T>
    A& operator << (T p)
    {
        std::cout << p;

        return *this;
    }
};


void test(void)
{
    A a;

    a<<1<<2<<3<<"www"<<2.5<<"\n";

    /* output:

    123www2.5

     */
}


}
