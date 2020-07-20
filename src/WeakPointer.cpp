#include "WeakPointer.hpp"
#include <iostream>
#include <memory>

namespace WeakPointer {

void test_cyclic(void);
class A;
class B;

void test(void)
{
    test_cyclic();
}

class A
{
public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }

    std::shared_ptr<B> b;
    // std::weak_ptr<B> b;
};

class B
{
public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }

    // std::shared_ptr<A> a;
    std::weak_ptr<A> a;
};

void test_cyclic()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    // cyclic pointing
    a->b = b;
    b->a = a;

    /* Output, if both pointers are shared_ptr

    A()
    B()

    ! No Destructors !
     */

    /* Output, if use at least one weak_ptr

    A()
    B()

    ~A()
    ~B()

    or (depends on who owns who, who is weak)

    ~B()
    ~A()

     */
}

} // namespace WeakPointer
