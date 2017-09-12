#include <iostream>
#include "Containers.hpp"
#include <set>
#include <map>
#include <unordered_map>

/*                         Standard Container Summary
 *
 *********************************************************************************
 *       * Sequence containers *
 *
 * vector<T>                A variable-size vector.
 * list<T>                  A doubly-linked list.
 * forward_list<T>          A singly-linked list
 * deque<T>                 A double-ended queue.
 *
 *********************************************************************************
 *       * Associative  containers *
 *
 * set<T>                   A set.
 * multiset<T>              A set in which a value can occur many times.
 * map<K,V>                 An assotiative array (ordered by Key).
 * multimap<K,V>            A map in which a key can accur many times.
 *
 * Properties:                                          For:
 * - sorted                                             - efficient store/restore
 * - based on balanced tree (binary search tree)
 * - unique key (or multi)
 *
 *********************************************************************************
 *
 *
 * unordered_map<K,V>       A map using a hashed lookup.
 * unordered_multimap<K,V>  A multimap using a hashed lookup
 * unordered_set<T>         A set using a hashed lookup.
 * unordered_multiset<T>    A multiset using a hashed lookup.
 *
 */

namespace Containers {

void test_set(void);
void test_map(void);

void test(void)
{
    test_set();
    test_map();
}

void test_set(void)
{
    typedef std::set<int> si;

    si s {1, 2, 3};

    si::const_iterator i = s.begin();

    s.insert(i, 5); //
    s.insert(4);

    for(int i: s)
    {
        std::cout << "i = " << i << std::endl;
    }

    /* Output:

    i = 1
    i = 2
    i = 3
    i = 4
    i = 5

    */

    typedef std::set<int, std::greater<int>> sig;

    sig s1 {1, 2, 3};

    for(int i: s1)
    {
        std::cout << "i = " << i << std::endl;
    }

    /* Output:

    i = 3
    i = 2
    i = 1

    */
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
