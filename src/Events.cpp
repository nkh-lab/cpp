#include <iostream>
#include <functional>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "Events.hpp"

namespace Events {

template <typename E>
class Event
{
public:
    typedef std::function<void(const E&)> THandler;

    int subscribe(const THandler& handler)
    {
        int handlerID = generateHandlerID(mHandlers);

        mHandlers.insert( std::pair<int /*handlerID*/, THandler>(handlerID, handler));

        return handlerID;
    }

    void unsubscribe(const int& handlerID)
    {
        mHandlers.erase(handlerID);
    }

    void rise(E val)
    {
        for(auto it = mHandlers.begin(); it != mHandlers.end(); ++it)
        {
            it->second(val);
        }
    }

private:
    std::map<int /*handlerID*/, THandler> mHandlers;

    template <typename M>
    int generateHandlerID(const M& m)
    {
        int ret;

        do
        {
            ret = rand();

        }while(ret == 0 || m.find(ret) != m.end());

        return ret;
    }
};


class Provider
{
public:
    Event<int> EventInt;
    Event<std::string> EventString;
    Event<bool> EventBool;
};


class Consumer
{
public:
    Consumer(const std::string& name, Provider& provider):mProvider(provider)
    {
        mName = name;

        using namespace std::placeholders;
        mEventIntHandlerID = mProvider.EventInt.subscribe(std::bind(&Consumer::onEventInt, this, _1));

        mProvider.EventString.subscribe([this](const std::string& val)
        {
            std::cout << __FUNCTION__ << ": " << mName << " string = " << val << std::endl;
        }
        );

        mProvider.EventBool.subscribe([this](const bool& val)
        {
            std::cout << __FUNCTION__ << ": " << mName << " bool = " << val << std::endl;
        }
        );
    }

    void unsubsribeFromEventInt(void)
    {
        mProvider.EventInt.unsubscribe(mEventIntHandlerID);
    }

private:
    std::string mName;
    int mEventIntHandlerID;
    Provider& mProvider;

    void onEventInt(int val)
    {
        std::cout << mName << " Consumer::onEventInt() val = " << val << std::endl;
    }
};

void test()
{
    Provider p;

    Consumer c1("Consumer1", p);
    Consumer c2("Consumer2", p);

    p.EventInt.rise(1);
    c1.unsubsribeFromEventInt();
    p.EventInt.rise(2);
    p.EventInt.rise(3);

    p.EventString.rise("string test");
    p.EventBool.rise(false);

    /* Output:

    Consumer2 Consumer::onEventInt() val = 1
    Consumer1 Consumer::onEventInt() val = 1
    Consumer2 Consumer::onEventInt() val = 2
    Consumer2 Consumer::onEventInt() val = 3
    operator(): Consumer1 string = string test
    operator(): Consumer2 string = string test
    operator(): Consumer2 bool = 0
    operator(): Consumer1 bool = 0

     */
}


}
