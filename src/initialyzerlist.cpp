#include "initialyzerlist.hpp"
#include <iostream>


clsInitialyzer::clsInitialyzer(std::initializer_list<std::string> l)
{
    std::cout << "clsInitialyzer::clsInitialyzer()" << std::endl;

    for(auto& s : l)
    {
        std::cout << s << std::endl;
    }

}

void initialyzerlist()
{
    std::cout << "initialyzer_list with 3 items" << std::endl;
    clsInitialyzer iz3 {"param0", "param1", "param2"};

    std::cout << "initialyzer_list with 5 items" << std::endl;
    clsInitialyzer iz5 {"param0", "param1", "param2", "param3", "param4"};
}
