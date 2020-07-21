#include "MyForwardList.hpp"

#include <iostream>

namespace MyForwardList {

void test(void)
{
    auto l = MyForwardList<int>();

    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    for (auto n = l.getHead(); n != nullptr; n = n->next)
    {
        std::cout << n->value << std::endl;
    }

    // the same via iterator
    for (auto& n : l)
    {
        std::cout << n << std::endl;
    }

    l.reverse();

    for (auto n = l.getHead(); n != nullptr; n = n->next)
    {
        std::cout << n->value << std::endl;
    }
}

} // namespace MyForwardList
