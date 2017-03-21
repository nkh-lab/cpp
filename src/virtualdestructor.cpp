#include <iostream>
#include "virtualdestructor.hpp"

namespace virtualdestructor {

class clsBase
{
public:
    clsBase()
    {
        std::cout<<"clsBase constructor"<<std::endl;
    }

    ~clsBase()
    {
        std::cout<<"clsBase destructor"<<std::endl;
    }
};

class clsBaseVD
{
public:
    clsBaseVD()
    {
        std::cout<<"clsBaseVD constructor"<<std::endl;
    }

    /* Virtual provides invoking of the derived classes destructor (at first, in our case - ~clsDerived())
     * during deleting base class object.
     * Avoids memory leaks.
     * So, all base classes should have virtual destructors!
     */
    virtual ~clsBaseVD()
    {
        std::cout<<"clsBaseVD destructor"<<std::endl;
    }
};

class clsDerived : public clsBase, public clsBaseVD
{
public:
    clsDerived():clsBase(),clsBaseVD()
    {
        std::cout<<"clsDerived constructor"<<std::endl;
    }

    ~clsDerived()
    {
        std::cout<<"clsDerived destructor"<<std::endl;
    }
};

void test(void)
{
    std::cout<<"+++ create base +++"<<std::endl;
    clsBase*   base   = new clsDerived();
     std::cout<<"+++ create parentVD +++"<<std::endl;
    clsBaseVD* baseVD = new clsDerived();

    std::cout<<"--- delete base ---"<<std::endl;
    delete base;
    std::cout<<"--- delete baseVD ---"<<std::endl;
    delete baseVD;
}

}


