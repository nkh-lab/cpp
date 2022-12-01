#include "AsyncToSync.h"

#include <atomic>
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

namespace AsyncToSync {

class AsyncDataProvider
{
public:
    using DataCB = std::function<void(const std::vector<int>& data)>;

    AsyncDataProvider(DataCB cb = nullptr)
        : requested_data_size_{0}
        , worker_exit_{false}
    {
        cb_ = cb;

        auto l = [&]() {
            std::vector<int> data;

            for (;;)
            {
                if (worker_exit_) break;

                if (requested_data_size_ && cb_)
                {
                    data.emplace_back(data.size() + 1);

                    if (data.size() == requested_data_size_)
                    {
                        cb_(data);
                        data.clear();
                        requested_data_size_ = 0;
                    }
                }

                std::this_thread::sleep_for(1s);
            }
        };

        worker_ = std::thread(l);
    }

    ~AsyncDataProvider()
    {
        worker_exit_ = true;
        worker_.join();
    }

    void RequestData(size_t requested_data_size) { requested_data_size_ = requested_data_size; }

private:
    DataCB cb_;
    std::thread worker_;
    std::atomic<size_t> requested_data_size_;
    std::atomic<bool> worker_exit_;
};

bool wait_data(int seconds, std::vector<int>& data, size_t size)
{
    printf("%s\n", __PRETTY_FUNCTION__);

    bool ret = false;

    std::mutex m;
    std::condition_variable cv;

    data.clear();

    auto cb = [&](const std::vector<int>& d) {
        std::unique_lock<std::mutex> lock(m);
        data = d;
        lock.unlock();
        cv.notify_one();
    };

    AsyncDataProvider adp(cb);

    adp.RequestData(size);

    std::unique_lock<std::mutex> lock(m);

    if (cv.wait_for(lock, seconds * 1s, [&]() { return !data.empty(); }))
    {
        ret = true;
    }

    return ret;
}

void test(void)
{
    printf("%s\n", __PRETTY_FUNCTION__);

    std::vector<int> data{};

    constexpr int kDataWaitTimeIn_s = 10;
    constexpr int kHappyRequestedDataSize = 5;
    constexpr int kUnhappyRequestedDataSize = 15;

    auto data_wait_time = kDataWaitTimeIn_s;

    printf("Happy case...\n");

    if (wait_data(data_wait_time, data, kHappyRequestedDataSize))
    {
        printf("Data came elier than %is, data:", data_wait_time);

        for (auto i : data) printf(" %i", i);
        printf("\n");
    }
    else
    {
        printf("%is timed out, no data!\n", data_wait_time);
    }

    printf("Unhappy case...\n");
    if (wait_data(data_wait_time, data, kUnhappyRequestedDataSize))
    {
        printf("Data came elier than %is, data:", data_wait_time);

        for (auto i : data) printf(" %i", i);
        printf("\n");
    }
    else
    {
        printf("%is timed out, no data!\n", data_wait_time);
    }
}

} // namespace AsyncToSync
