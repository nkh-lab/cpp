#include "Exceptions.hpp"

#include <iostream>

/*
 * Helpful links:
 * https://isocpp.org/wiki/faq/exceptions#ctor-exceptions
 *
 */

namespace Exceptions {

class A
{
public:
    A()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        throw std::exception();
    }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

void test(void)
{
    try
    {
        A a;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    /* Output:

    Hello World!
    Exceptions::A::A()
    std::exception

    */
}

} // namespace Exceptions
