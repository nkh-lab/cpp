#include "UsingVsTypedef.hpp"

#include <iostream>

// Using namespace
using namespace std;

// Namespace alias
namespace my_std = std;

namespace UsingVsTypedef {

template <int I>
class ConstInt
{
public:
    int getValue() { return I; }
};

// Type alias
using SignedInt_u = signed int;
using ConstInt_3_u = ConstInt<3>;
// Typedef analogue
typedef signed int SignedInt_t;
typedef ConstInt<3> ConstInt_3_t;

// Template alias
template <int V>
using ConstInt_u = ConstInt<V>;
// No typedef analogue

void test(void)
{
    SignedInt_u siu = 1;
    SignedInt_t sit = 2;

    cout << siu << endl;
    cout << sit << endl;

    cout << ConstInt_3_u().getValue() << endl;
    cout << ConstInt_3_t().getValue() << endl;
    my_std::cout << ConstInt_u<4>().getValue() << my_std::endl;
}
} // namespace UsingVsTypedef
