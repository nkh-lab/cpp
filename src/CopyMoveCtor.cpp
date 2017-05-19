#include <iostream>
#include <utility> // std::move

#include "CopyMoveCtor.hpp"

namespace CopyMoveCtor {

class A
{
    int* i;

public:
    int get_i(){return *i;}

    A(int i_i)
    {
        i = new(int);

        *i = i_i;

        std::cout << this << " Plain Constructor, *i = " << *i << ", i = " << i << std::endl;
    }

    A(A& c)
    {
        i = new(int);

        *i = *c.i;

        std::cout << this << " Copy  Constructor, *i = " << *i << ", i = " << i << std::endl;
    }

    A(A&& m)
    {
        i = std::move(m.i);

        std::cout << this << " Move  Constructor, *i = " << *i << ", i = " << i << std::endl;
    }

    ~A()
    {
        std::cout << this << " Destructor, *i = " << *i << ", i = " << i << std::endl;

        if (i == nullptr)
        /*
            To supress runtime error (because we steel 'i' during move):
            *** Error in `/home/nkh/my/cpp/build/cpp': double free or corruption (fasttop): 0x0000000002363050 ***
            The program has unexpectedly finished.
        */
        {
            delete(i);
        }
    }

    A& operator = (A& c)
    {
        *i = *c.i;

        std::cout << this << " Copy Assigment Operator, *i = " << *i << ", i = " << i << std::endl;

        return *this;
    }

    A& operator = (A&& m)
    {
        i = std::move(m.i);

        std::cout << this << " Move Assigment Operator, *i = " << *i << ", i = " << i << std::endl;

        return *this;
    }
};

void test(void)
{
    A a(1);

    A ca(a);            // Copy Constructor

    A b(2);
    A mb = std::move(b);// Move Constructor

    std::cout << b.get_i() << std::endl;

    A c(3);
    A d(4);
    A e(5);

    d = c;           // Copy Assigment
    d = std::move(e);// Move Assigment

    /* Output:

    0x7ffd9f29cf10 Plain Constructor, *i = 1, i = 0x2249c30
    0x7ffd9f29cf20 Copy  Constructor, *i = 1, i = 0x2249c50
    0x7ffd9f29cf30 Plain Constructor, *i = 2, i = 0x2249c70
    0x7ffd9f29cf40 Move  Constructor, *i = 2, i = 0x2249c70
    2
    0x7ffd9f29cf50 Plain Constructor, *i = 3, i = 0x2249c90
    0x7ffd9f29cf60 Plain Constructor, *i = 4, i = 0x2249cb0
    0x7ffd9f29cf70 Plain Constructor, *i = 5, i = 0x2249cd0
    0x7ffd9f29cf60 Copy Assigment Operator, *i = 3, i = 0x2249cb0
    0x7ffd9f29cf60 Move Assigment Operator, *i = 5, i = 0x2249cd0
    0x7ffd9f29cf70 Destructor, *i = 5, i = 0x2249cd0
    0x7ffd9f29cf60 Destructor, *i = 5, i = 0x2249cd0
    0x7ffd9f29cf50 Destructor, *i = 3, i = 0x2249c90
    0x7ffd9f29cf40 Destructor, *i = 2, i = 0x2249c70
    0x7ffd9f29cf30 Destructor, *i = 2, i = 0x2249c70
    0x7ffd9f29cf20 Destructor, *i = 1, i = 0x2249c50
    0x7ffd9f29cf10 Destructor, *i = 1, i = 0x2249c30

     */
}

}
