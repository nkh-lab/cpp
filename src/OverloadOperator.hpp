#ifndef OVERLOADOPERATOR_HPP
#define OVERLOADOPERATOR_HPP

#include <iostream>

namespace OverloadOperator {

class A
{
    int storage;

public:
    /*
     * Overloading should be in the header file!!!
     * Because compilator needs to see implentation where it used.
     */

    // internal operator overloading with Template parameter
    template <typename T>
    A& operator<<(T p)
    {
        std::cout << p;

        return *this;
    }
};

// external operator overloading
template <typename T>
A& operator+(A& a, T p)
{
    std::cout << p;

    return a;
}

void test(void);

} // namespace OverloadOperator
#endif
