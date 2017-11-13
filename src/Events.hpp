#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <functional>
#include <map>
#include <algorithm>
#include <mutex>

namespace Events {

class VoidClass
{

};

class UnsafeSyncPolicy // without synchronization mechanism, e.g. event provider and consumer are in the single thread
{
public:
    typedef VoidClass Locker_t;

    UnsafeSyncPolicy(Locker_t& locker) {}
};

class SafeSyncPolicy // with synchronization mechanism
{
public:
    typedef std::mutex Locker_t;

    SafeSyncPolicy(Locker_t& locker): mLocker(locker)
    {
        mLocker.lock();
    }

    ~SafeSyncPolicy()
    {
        mLocker.unlock();
    }

private:
    Locker_t&  mLocker;
};

template <typename TSyncPolicy, typename... TEvtArgs>
class Event
{
    typedef std::function<void(const TEvtArgs&...)> Handler_t;
    typedef std::map<int /*handlerID*/, Handler_t>  Handlers_t;

    Handlers_t mHandlers;

    typename TSyncPolicy::Locker_t mLocker;

public:
    int subscribe(const Handler_t& handler)
    {
        TSyncPolicy guard(mLocker);

        int handlerID = generateHandlerID();

        mHandlers.insert( std::pair<int /*handlerID*/, Handler_t>(handlerID, handler));

        return handlerID;
    }

    void unsubscribe(const int& handlerID)
    {
        TSyncPolicy guard(mLocker);

        mHandlers.erase(handlerID);
    }

    void rise(const TEvtArgs&... val)
    {
        TSyncPolicy guard(mLocker);

        for(auto it = mHandlers.begin(); it != mHandlers.end(); ++it)
        {
            it->second(val...);
        }
    }

private:
    int generateHandlerID()
    {
        int ret;

        do
        {
            ret = rand();

        }while(ret == 0 || mHandlers.find(ret) != mHandlers.end());

        return ret;
    }
};







}

#endif
