#include "MyArray.hpp"

#include <iostream>

#include <list>

namespace MyArray {

template <typename T, size_t S>
class MyArray
{
public:
    T& operator[](size_t n) { return m_Data[n]; }

    // for iterating
    T* begin() { return m_Data; }
    T* end() { return (m_Data + S); }

private:
    T m_Data[S];
};

void test()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    MyArray<int, 3> mai;

    mai[0] = 1;
    mai[1] = 2;
    mai[2] = 3;

    for (auto& i : mai)
    {
        std::cout << i << std::endl;
    }

    MyArray<std::string, 3> mas;

    mas[0] = "one";
    mas[1] = "two";
    mas[2] = "three";

    for (auto& s : mas)
    {
        std::cout << s << std::endl;
    }
}

} // namespace MyArray
