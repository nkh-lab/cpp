#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v);

namespace IO {

void test(void);

}



#endif
