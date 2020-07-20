#include "SyncQueue.hpp"

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

namespace SyncQueue {

template <typename T>
class SyncQueue
{
    std::queue<T> m_Que;
    std::mutex m_Lock;
    std::condition_variable m_ConVar;

public:
    void enque(T item)
    {
        std::unique_lock<std::mutex> lock(m_Lock);
        m_Que.push(item);
        lock.unlock();
        m_ConVar.notify_all();
    }

    T deque()
    {
        std::unique_lock<std::mutex> lock(m_Lock);

        do
        {
            m_ConVar.wait(lock);

        } while (m_Que.size() == 0); // extra check from spontaneous notifications

        auto ret = m_Que.front();
        m_Que.pop();

        return ret;
    }
};

void test()
{
    using namespace std::chrono_literals;

    SyncQueue<int> sq;

    std::thread consumer([&sq]() {
        std::cout << "consumer" << std::endl;

        for (;;)
        {
            std::cout << sq.deque() << std::endl;
        }
    });

    std::thread provider([&sq]() {
        std::this_thread::sleep_for(1s);
        sq.enque(1);
        std::this_thread::sleep_for(3s);
        sq.enque(2);
        std::this_thread::sleep_for(5s);
        sq.enque(3);
    });

    consumer.join();
}

} // namespace SyncQueue
