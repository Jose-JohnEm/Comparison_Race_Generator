#include "crg.hpp"

company::company()
{
    
}

void company::setName(std::string data)
{
    cName = data;
}

void company::setValues(std::vector<std::string> data)
{
    char *tmp{nullptr};

    for (int i{0}; i < data.size(); i++) {
        tmp = new char[data[i].length() + 1];
        strcpy(tmp, data[i].c_str());
        cValues.push_back(atoi(tmp));
        delete [] tmp;
    }
    std::cout << "Welcome " << cName << " !\n";
}

company::~company()
{

}