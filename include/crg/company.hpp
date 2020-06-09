
#ifndef __COMPANY__
#define __COMPANY__

#include <string>

class company
{
    public:
        company();
        ~company();

        void setName(std::string data);
        void setValues(std::vector<std::string>);

    private:
        std::string cName;
        std::vector<int> cValues;
};

#endif