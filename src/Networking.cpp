#include "Networking.hpp"

#include <cstring>
#include <iostream>

#include <arpa/inet.h>
#include <ifaddrs.h>

namespace Networking {

void printIpAdresses();
bool containsIP4Adress(const char* address);

void test(void)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    printIpAdresses();

    const char* kCheckIP4AdressTrue = "10.44.129.155";
    const char* kCheckIP4AdressFalse = "198.18.34.15";

    std::cout << "containsIP4Adress(" << kCheckIP4AdressTrue
              << "): " << containsIP4Adress(kCheckIP4AdressTrue) << "\n";
    std::cout << "containsIP4Adress(" << kCheckIP4AdressFalse
              << "): " << containsIP4Adress(kCheckIP4AdressFalse) << "\n";
}

/*
 * Based on:
 * https://stackoverflow.com/a/265978/5130269
 *
 * Output example:
 *
 *      lo IP Address 127.0.0.1
 *      wlp9s0 IP Address 192.168.0.22
 *      lo IP Address ::1
 *      wlp9s0 IP Address fe80::78c9:be42:4b9f:17a4
 */

void printIpAdresses()
{
    ifaddrs* ifAddrStruct = NULL;
    ifaddrs* ifa = NULL;
    void* tmpAddrPtr = NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (!ifa->ifa_addr)
        {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) // check it is IP4
        {
            // is a valid IP4 Address
            tmpAddrPtr = &(reinterpret_cast<sockaddr_in*>(ifa->ifa_addr))->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
        }
        else if (ifa->ifa_addr->sa_family == AF_INET6) // check it is IP6
        {
            // is a valid IP6 Address
            tmpAddrPtr = &(reinterpret_cast<sockaddr_in6*>(ifa->ifa_addr))->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
        }
    }
    if (ifAddrStruct != NULL) freeifaddrs(ifAddrStruct);
}

bool containsIP4Adress(const char* address)
{
    bool ret = false;

    ifaddrs* ifAddrStruct = nullptr;

    getifaddrs(&ifAddrStruct);

    for (ifaddrs* ifa = ifAddrStruct; ifa != nullptr; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr != nullptr && ifa->ifa_addr->sa_family == AF_INET) // check it is IP4
        {
            void* tmpAddrPtr = &(reinterpret_cast<sockaddr_in*>(ifa->ifa_addr))->sin_addr;

            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

            if (std::strcmp(address, addressBuffer) == 0)
            {
                ret = true;
                break;
            }
        }
    }

    if (ifAddrStruct != nullptr) freeifaddrs(ifAddrStruct);

    return ret;
}

} // namespace Networking
