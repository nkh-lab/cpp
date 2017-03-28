#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <vector>

namespace IO {

void test(void);

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v);

}



#endif
