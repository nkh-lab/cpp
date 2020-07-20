#ifndef OVERLOADOPERATOR_HPP
#define OVERLOADOPERATOR_HPP

namespace OverloadOperator {

class A
{
    int storage;

public:
    /*
     * Overloading should be in the header file!!!
     * Because compilator needs to see implentation where it used.
     */

    // overload operator with Template parameter
    template <typename T>
    A& operator<<(T p)
    {
        std::cout << p;

        return *this;
    }
};

void test(void);

} // namespace OverloadOperator
#endif
