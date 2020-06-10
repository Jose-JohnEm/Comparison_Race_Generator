
#include "crg.hpp"
#include <cstdlib>

void my_error(std::string msg)
{
    std::cout << msg;
    exit(1);
}

char *my_strdup(char const *str)
{
    std::string tmp{str};
    char *newer{strdup(tmp.c_str())};

    return newer;
}