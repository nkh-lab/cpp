#include <iostream>
#include <utility> // std::move

#include "CopyMoveCtor.hpp"

namespace CopyMoveCtor {

class A
{
    int* i = new(int);

public:
    int get_i(){return *i;}

    A(int i_i)
    {
        *i = i_i;

        std::cout << this << " Plain Constructor, *i = " << *i << ", i = " << i << std::endl;
    }

    A(A& c)
    {
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

    /* output:

    0x7ffd05d35250 Plain Constructor, *i = 1, i = 0x2160010
    0x7ffd05d35260 Copy  Constructor, *i = 1, i = 0x2160030
    0x7ffd05d35270 Plain Constructor, *i = 2, i = 0x2160050
    0x7ffd05d35280 Move  Constructor, *i = 2, i = 0x2160050
    2
    0x7ffd05d35290 Plain Constructor, *i = 3, i = 0x2160090
    0x7ffd05d352a0 Plain Constructor, *i = 4, i = 0x21600b0
    0x7ffd05d352b0 Plain Constructor, *i = 5, i = 0x21600d0
    0x7ffd05d352a0 Copy Assigment Operator, *i = 3, i = 0x21600b0
    0x7ffd05d352a0 Move Assigment Operator, *i = 5, i = 0x21600d0
    0x7ffd05d352b0 Destructor, *i = 5, i = 0x21600d0
    0x7ffd05d352a0 Destructor, *i = 5, i = 0x21600d0
    0x7ffd05d35290 Destructor, *i = 3, i = 0x2160090
    0x7ffd05d35280 Destructor, *i = 2, i = 0x2160050
    0x7ffd05d35270 Destructor, *i = 2, i = 0x2160050
    0x7ffd05d35260 Destructor, *i = 1, i = 0x2160030
    0x7ffd05d35250 Destructor, *i = 1, i = 0x2160010

     */
}

}
