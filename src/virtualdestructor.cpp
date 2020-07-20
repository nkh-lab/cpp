#include "virtualdestructor.hpp"
#include <iostream>

namespace virtualdestructor {

class clsBase
{
public:
    clsBase() { std::cout << "clsBase constructor" << std::endl; }

    ~clsBase() { std::cout << "clsBase destructor" << std::endl; }
};

class clsDerived : public clsBase
{
public:
    clsDerived() { std::cout << "clsDerived constructor" << std::endl; }

    ~clsDerived() { std::cout << "clsDerived destructor" << std::endl; }
};

class clsBaseVD
{
public:
    clsBaseVD() { std::cout << "clsBaseVD constructor" << std::endl; }

    virtual ~clsBaseVD() { std::cout << "clsBaseVD destructor" << std::endl; }
};

class clsDerivedVD : public clsBaseVD
{
public:
    clsDerivedVD() { std::cout << "clsDerivedVD constructor" << std::endl; }

    ~clsDerivedVD() { std::cout << "clsDerivedVD destructor" << std::endl; }
};

void test(void)
{
    std::cout
        << "Casting base to derived class and destroy it WITHOUT Virtual Destructor in base class"
        << std::endl;
    clsBase* base = new clsDerived();
    delete base;

    /* Output:

    clsBase constructor
    clsDerived constructor
    clsBase destructor

     */
    // ! no clsDerived destructor

    std::cout
        << "Casting base to derived class and destroy it WITH Virtual Destructor in base class"
        << std::endl;
    clsBaseVD* baseVD = new clsDerivedVD();
    delete baseVD;

    /* Output:

    clsBaseVD constructor
    clsDerivedVD constructor
    clsDerivedVD destructor
    clsBaseVD destructor

     */

    /* Summary:
     *
     * 1. All base classes should have a Virtual Destructors to avoid a possible memmory leak.
     * 2. Because class which contains at least one virtual method can only be used like a base
     * class it should contains Virtual Destructor.
     * 3. The same is for Interfaces - pure virtual or abstract classes.
     *
     */
}
} // namespace virtualdestructor
