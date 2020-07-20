#include <functional>
#include <iostream>

#include "Function.hpp"

namespace Function {

class CbProvider
{
public:
    CbProvider() {}

    std::function<void(std::string)> cb;

    void activateCB(std::string reason)
    {
        if (cb != nullptr) cb(reason);
    }
};

class CbHandler
{
public:
    CbHandler(CbProvider& p)
    {
        using namespace std::placeholders;
        p.cb = std::bind(&CbHandler::onCB, this, _1);
    }

    void onCB(std::string s) { std::cout << "onCB s = " << s << std::endl; }
};

void test(void)
{
    std::function<void()> f1 = []() { std::cout << "Hello from target1" << std::endl; };

    if (f1 == nullptr)
        std::cout << "f1 = nullptr" << std::endl;
    else
        std::cout << "f1 = not nullptr" << std::endl;

    f1();

    f1 = nullptr;

    if (f1 == nullptr)
        std::cout << "f1 = nullptr" << std::endl;
    else
        std::cout << "f1 = not nullptr" << std::endl;

    // f1(); // - comment out to avoid crash

    /* Output:

    Hello World!
    f1 = not nullptr
    Hello from target1
    f1 = nullptr
    terminate called after throwing an instance of 'std::bad_function_call'
      what():  bad_function_call
    The program has unexpectedly finished.
    /.../cpp crashed.

    */

    // Test bind

    CbProvider provider;

    CbHandler handler(provider);

    provider.activateCB("Send CB#1");
    provider.activateCB("Send CB#2");

    /* Output:

    onCB s = Send CB#1
    onCB s = Send CB#2

    */
}

} // namespace Function
