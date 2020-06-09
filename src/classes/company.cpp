#include "crg.hpp"

company::company()
{
    std::cout << "A new Company appear\n";
}

void company::setName(std::string data)
{
    cName = data;
}

void company::setValues(std::vector<std::string> data)
{
    char *tmp{nullptr};

    for (int i{0}; i < data.max_size(); i++) {
        tmp = new char[data[i].length() + 1];
        strcpy(tmp, data[i].c_str());
        cValues.push_back(atoi(tmp));
        delete [] tmp;
    }
    std::cout << "Welcome " << cName << " !\n";
}

company::~company()
{
    std::cout << "The company disappear\n";
}