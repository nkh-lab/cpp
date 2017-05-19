#include <iostream>
#include "Containers.hpp"
#include <map>
#include <unordered_map>

/* Standard Container Summary
 *
 * vector<T>                A variable-size vector.
 * list<T>                  A doubly-linked list.
 * forward_list<T>          A singly-linked list
 * deque<T>                 A double-ended queue.
 * set<T>                   A set.
 * multiset<T>              A set in which a value can occur many times.
 * map<K,V>                 An assotiative array (ordered by Key).
 * multimap<K,V>            A map in which a key can accur many times.
 * unordered_map<K,V>       A map using a hashed lookup.
 * unordered_multimap<K,V>  A multimap using a hashed lookup
 * unordered_set<T>         A set using a hashed lookup.
 * unordered_multiset<T>    A multiset using a hashed lookup.
 */

namespace Containers {

void test_map(void);

void test(void)
{
    test_map();
}

void test_map(void)
{
    std::map<int,std::string> m {
        {4, "four"},
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    std::unordered_map<int,std::string> um {
        {4, "four"},
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    std::cout << "map<K,V>:" << std::endl;

    for(auto i = m.begin(); i != m.end(); i++)
    {
        std::cout << "Key: " << i->first << ", Value: " << i->second << std::endl;
    }

    std::cout << "unordered_map<K,V>:" << std::endl;

    for(auto i = um.begin(); i != um.end(); i++)
    {
        std::cout << "Key: " << i->first << ", Value: " << i->second << std::endl;
    }

    /* Output:

    map<K,V>:
    Key: 0, Value: zero
    Key: 1, Value: one
    Key: 2, Value: two
    Key: 3, Value: three
    Key: 4, Value: four

    unordered_map<K,V>:
    Key: 3, Value: three
    Key: 4, Value: four
    Key: 0, Value: zero
    Key: 1, Value: one
    Key: 2, Value: two

    */
}

}
