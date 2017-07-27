#include <iostream>
#include <functional>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "Events.hpp"

namespace Events {

class Provider
{
public:
    typedef std::function<void(int)> EventInt;

     int subscribeToEventInt(const EventInt& handler)
     {
         int handlerID = generateHandlerID();

         mHandlers.insert( std::pair<int /*handlerID*/, EventInt>(handlerID, handler));

         return handlerID;
     }

     void unsubscribeFromEventInt(const int& handlerID)
     {
         mHandlers.erase(handlerID);
     }

     void riseEvent(int val)
     {
         for(auto it = mHandlers.begin(); it != mHandlers.end(); ++it)
         {
             it->second(val);
         }
     }

private:
     std::map<int /*handlerID*/, EventInt> mHandlers;

     int generateHandlerID(void)
     {
         int ret;

         do
         {
             ret = rand();

         }while(ret == 0 || mHandlers.find(ret) != mHandlers.end());

         return ret;
     }
};


class Consumer
{
public:
    Consumer(const std::string& name, Provider& provider):mProvider(provider)
    {
        mName = name;

        using namespace std::placeholders;
        mEventIntHandlerID = mProvider.subscribeToEventInt(std::bind(&Consumer::onEventInt, this, _1));
    }

    void unsubsribeFromProvider(void)
    {
        mProvider.unsubscribeFromEventInt(mEventIntHandlerID);
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

    p.riseEvent(1);
    c1.unsubsribeFromProvider();
    p.riseEvent(2);
    p.riseEvent(3);

    /* Output:

    Consumer2 Consumer::onEventInt() val = 1
    Consumer1 Consumer::onEventInt() val = 1
    Consumer2 Consumer::onEventInt() val = 2
    Consumer2 Consumer::onEventInt() val = 3

     */
}


}
