#include "Promise.hpp"
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

namespace Promise {

void p_loop(std::promise<bool> p, int delayInSec)
{
    std::this_thread::sleep_for(std::chrono::seconds(delayInSec));

    p.set_value(true);
}

void test(void)
{
    std::cout << "Promise start" << std::endl;

    std::promise<bool> p1;
    std::promise<bool> p2;

    std::future<bool> f1 = p1.get_future();
    std::future<bool> f2 = p2.get_future();

    std::thread t1(p_loop, std::move(p1), 10);
    std::thread t2(p_loop, std::move(p2), 10);

    auto f2_status = f2.wait_for(std::chrono::seconds(1));
    auto f1_status = f1.wait_for(std::chrono::seconds(20)); // f1.wait();

    if (f1_status == std::future_status::ready)
    {
        std::cout << "Promise #1 ended with Value  = " << f1.get() << std::endl;
    }
    else if (f1_status == std::future_status::timeout)
    {
        std::cout << "Promise #1 ended with Status = "
                  << "timeout" << std::endl;
    }

    if (f2_status == std::future_status::ready)
    {
        std::cout << "Promise #2 ended with Value = " << f2.get() << std::endl;
    }
    else if (f2_status == std::future_status::timeout)
    {
        std::cout << "Promise #2 ended with Status = "
                  << "timeout" << std::endl;
    }

    t1.join();
    t2.join();

    /* output:

    Promise start
    Promise #1 ended with Value  = 1
    Promise #2 ended with Status = timeout

     */
}

} // namespace Promise
