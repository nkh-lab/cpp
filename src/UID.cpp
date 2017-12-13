#include <iostream>
#include "uuid/uuid.h"
/*
 * ! For Ubuntu: sudo apt-get install uuid-dev
 */
namespace UID {

void test(void)
{
    uuid_t uuid;
    char c_uuid[36];

    uuid_generate(uuid);
    // convert to string
    uuid_unparse(uuid, c_uuid);

    std::cout << "uuid = " << c_uuid << std::endl;

    /* Output:

    uuid = 000a697f-1166-4d9d-9425-a537b36b483f

    */
}

}
