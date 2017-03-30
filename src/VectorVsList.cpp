#include <vector>
#include <iostream>

#include "VectorVsList.hpp"
#include "IO.hpp" // to cout vector

namespace VectorVsList {

void test(void)
{
    std::vector<int> vi(5, 1);// 5 items inited by 1

    std::cout << "vi.capacity() = " << vi.capacity() << std::endl;
    std::cout << "vi.size() = " << vi.size() << std::endl;
    std::cout << "vi = " << vi << std::endl;

    /* output:

    vi.capacity() = 5
    vi.size() = 5
    vi = [1, 1, 1, 1, 1]

     */

    vi.push_back(123);

    std::cout << "vi.capacity() = " << vi.capacity() << std::endl;
    std::cout << "vi.size() = " << vi.size() << std::endl;
    std::cout << "vi = " << vi << std::endl;

    /* output:

    vi.capacity() = 10        - ! own algorithm
    vi.size() = 6
    vi = [1, 1, 1, 1, 1, 123]

     */
}

}
