#include "crg.hpp"

company::company()
{
    cName = "Inconnu";
    std::cout << "A new Company appear\n";
}

company::~company()
{
    std::cout << "The company disappear\n";
}