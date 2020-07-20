#include <iostream>
#include <utility> // std::move

#include "CopyMoveCtor.hpp"

namespace CopyMoveCtor {

class A
{
    int* i = nullptr;

public:
    int get_i() { return *i; }

    A() { std::cout << this << " Default Constructor, i = NULL" << std::endl; }

    A(int i_i)
    {
        i = new (int);

        *i = i_i;

        std::cout << this << " Plain Constructor, *i = " << *i << ", i = " << i << std::endl;
    }

    A(A& c)
    {
        i = new (int);

        *i = *c.i;

        std::cout << this << " Copy  Constructor, *i = " << *i << ", i = " << i << std::endl;
    }

    A(A&& m)
    {
        i = m.i; // or i = std::move(m.i) for non pointers

        std::cout << this << " Move  Constructor, *i = " << *i << ", i = " << i << std::endl;

        m.i = nullptr; // to avoid double deleting in destrctor
    }

    ~A()
    {
        if (i != nullptr)
        {
            std::cout << this << " Destructor, *i = " << *i << ", i = " << i << std::endl;
            delete (i);
            i = nullptr;
        }
        else
        {
            std::cout << this << " Destructor, i = NULL" << std::endl;
        }
    }

    A& operator=(A& c)
    {
        if (i == nullptr) i = new (int);

        *i = *c.i;

        std::cout << this << " Copy Assigment Operator, *i = " << *i << ", i = " << i << std::endl;

        return *this;
    }

    A& operator=(A&& m)
    {
        if (i != nullptr)
        {
            std::cout << this << " Delete before moving, *i = " << *i << ", i = " << i << std::endl;
            delete (i);
        }

        i = m.i; // or i = std::move(m.i) for non pointers

        std::cout << this << " Move Assigment Operator, *i = " << *i << ", i = " << i << std::endl;

        m.i = nullptr; // to avoid double deleting in destrctor

        return *this;
    }
};

void test(void)
{
#if 0
    {
        A a(1);

        A ca(a);            // Copy Constructor

        A b(2);
        A mb = std::move(b);// Move Constructor

        std::cout << mb.get_i() << std::endl;

        A c(3);
        A d(4);
        A e(5);

        d = c;           // Copy Assigment
        d = std::move(e);// Move Assigment

        /* Output:

        0x7ffc66251f70 Plain Constructor, *i = 1, i = 0x1fadc30
        0x7ffc66251f80 Copy  Constructor, *i = 1, i = 0x1fadc50
        0x7ffc66251f90 Plain Constructor, *i = 2, i = 0x1fadc70
        0x7ffc66251fa0 Move  Constructor, *i = 2, i = 0x1fadc70
        2
        0x7ffc66251fb0 Plain Constructor, *i = 3, i = 0x1fadc90
        0x7ffc66251fc0 Plain Constructor, *i = 4, i = 0x1fadcb0
        0x7ffc66251fd0 Plain Constructor, *i = 5, i = 0x1fadcd0
        0x7ffc66251fc0 Copy Assigment Operator, *i = 3, i = 0x1fadcb0
        0x7ffc66251fc0 Delete before moving, *i = 3, i = 0x1fadcb0
        0x7ffc66251fc0 Move Assigment Operator, *i = 5, i = 0x1fadcd0
        0x7ffc66251fd0 Destructor, i = NULL
        0x7ffc66251fc0 Destructor, *i = 5, i = 0x1fadcd0
        0x7ffc66251fb0 Destructor, *i = 3, i = 0x1fadc90
        0x7ffc66251fa0 Destructor, *i = 2, i = 0x1fadc70
        0x7ffc66251f90 Destructor, i = NULL
        0x7ffc66251f80 Destructor, *i = 1, i = 0x1fadc50
        0x7ffc66251f70 Destructor, *i = 1, i = 0x1fadc30

         */
    }
#endif

#if 0
    {
        A a;            // Default Constructor
        A a5 = A(5);    // Plain Constructor
        a = a5;         // Copy Assigment Operator

        /* Output

        0x7ffe1c282e50 Default Constructor, i = NULL
        0x7ffe1c282e60 Plain Constructor, *i = 5, i = 0x227cc30
        0x7ffe1c282e50 Copy Assigment Operator, *i = 5, i = 0x227cc50
        0x7ffe1c282e60 Destructor, *i = 5, i = 0x227cc30
        0x7ffe1c282e50 Destructor, *i = 5, i = 0x227cc50

         */
    }
#endif

#if 0
    {
        A a7 = 7; // Plain Constructor, implicit invoking

        /* Output

        0x7fff541c2020 Plain Constructor, *i = 7, i = 0x25a7c30
        0x7fff541c2020 Destructor, *i = 7, i = 0x25a7c30

         */
    }
#endif

#if 0
    {
        A a8; // Default Constructor

        a8 = 8; // Plain Constructor, implicit invoking + Move Assigment Operator !

        /* Output

        0x7fff57f0a640 Default Constructor, i = NULL
        0x7fff57f0a650 Plain Constructor, *i = 8, i = 0xf4dc30
        0x7fff57f0a640 Move Assigment Operator, *i = 8, i = 0xf4dc30
        0x7fff57f0a650 Destructor, i = NULL
        0x7fff57f0a640 Destructor, *i = 8, i = 0xf4dc30

          */
    }
#endif

#if 1
    {
        A a9(9); // Plain Constructor

        a9 = 10; // Plain Constructor, implicit invoking + Move Assigment Operator !

        /* Output

        0x7fff451b68e0 Plain Constructor, *i = 9, i = 0x1c1dc30
        0x7fff451b68f0 Plain Constructor, *i = 10, i = 0x1c1dc50
        0x7fff451b68e0 Delete before moving, *i = 9, i = 0x1c1dc30
        0x7fff451b68e0 Move Assigment Operator, *i = 10, i = 0x1c1dc50
        0x7fff451b68f0 Destructor, i = NULL
        0x7fff451b68e0 Destructor, *i = 10, i = 0x1c1dc50

          */
    }
#endif
}

} // namespace CopyMoveCtor
