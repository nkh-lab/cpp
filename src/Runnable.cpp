#include "Runnable.hpp"

#include <atomic>
#include <functional>
#include <iostream>
#include <thread>

using namespace std::placeholders;
using namespace std::chrono_literals;

namespace Runnable {

class IRunnable
{
public:
    using Routine = std::function<void (const std::atomic_bool& request_to_stop)>;

    virtual ~IRunnable() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
};

class Runnable : IRunnable
{
public:
    Runnable(Routine routine)
        : m_routine {routine}
        , m_request_to_stop{false}
    {

    }

    virtual ~Runnable()
    {
        stop();
    }

    void start() override
    {
        m_thread = std::thread(m_routine, std::ref(m_request_to_stop));
    }

    void stop() override
    {
        m_request_to_stop = true;
        if(m_thread.joinable()) m_thread.join();
    }

private:
    Routine m_routine;
    std::thread m_thread;
    std::atomic_bool m_request_to_stop;
};

class MyClass : public Runnable
{
public:
    MyClass()
        : Runnable(std::bind(&MyClass::routine, this, _1))
    {

    }

private:
    void routine(const std::atomic_bool& request_to_stop)
    {
        size_t i = 0;

        for(;;)
        {
            if (request_to_stop) break;
            std::cout << __PRETTY_FUNCTION__ << request_to_stop << ", i = " << i << std::endl;
            ++i;
            std::this_thread::sleep_for(1s);
        }
    }
};

void test(void)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    MyClass mc;

    Runnable r([](const std::atomic_bool& request_to_stop)
    {
        size_t i = 0;

        for(;;)
        {
            if (request_to_stop) break;
            std::cout << __PRETTY_FUNCTION__ << ", i = " << i << std::endl;
            ++i;
            std::this_thread::sleep_for(1s);
        }
    });

    mc.start();
    r.start();

    std::this_thread::sleep_for(3s);

    mc.stop();
    r.stop();

    std::this_thread::sleep_for(3s);
}
}
