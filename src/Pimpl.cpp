#include "Pimpl.hpp"

#include <iostream>
#include <memory>

namespace Pimpl {

/*
 * Shared header file
 */

class PimplImpl;

class Pimpl
{
public:
    Pimpl();

    void method();

private:
    std::unique_ptr<PimplImpl> m_impl;
};

/*
 * Hidden implementation file
 */

class PimplImpl
{
public:
    void method()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

Pimpl::Pimpl()
    : m_impl{std::make_unique<PimplImpl>()}
{

}

void Pimpl::method()
{
    m_impl->method();
}

void test()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    Pimpl().method();
}

}
