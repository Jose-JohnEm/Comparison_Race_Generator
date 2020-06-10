/*
    Jonathan Emmanuel Jose
    Comparison Race Generator
*/

#include "crg.hpp"

int main(int ac, char **av)
{
    if (ac == 1) std::cout << "Nothing to compare\n";
    else if (ac > 2) std::cout << "Too many arguments\n";
    else displayer(parsor(av[1]));

    return 0;
}
