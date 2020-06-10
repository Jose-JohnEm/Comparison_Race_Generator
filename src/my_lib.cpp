
#include "crg.hpp"
#include <cstdlib>

void my_error(std::string const msg)
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

bool isanum(char const *str)
{
    for (int i{0}; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    return true;
}