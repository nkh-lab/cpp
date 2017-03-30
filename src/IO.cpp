#include "IO.hpp"

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    size_t last = v.size() - 1;

    for(size_t i = 0; i < v.size(); ++i)
    {
        out << v[i];
        if (i != last) out << ", ";
    }
    out << "]";
    return out;
}


namespace IO {

void test(void)
{
    std::vector<int> vi = {1, 2, 3, 4, 5, 6};
    std::vector<char> vc = {'a', 'b', 'c', 'd', 'e', 'f'};

    std::cout << vi << std::endl;
    std::cout << vc << std::endl;

    /* output:

    [1, 2, 3, 4, 5, 6]
    [a, b, c, d, e, f]

     */
}

/*
 *  Overload output stream operator for vector<T>
 */


}// namespace IO


