#ifndef __SPECS__
#define __SPECS__

#include <string>

class specs
{
    public:
        specs();
        ~specs();

        void setUnit(std::string unit);
        void setTimes(std::vector<std::string> times);

    private:
        std::string sUnit;
        std::vector<std::string> sTimes;
};

#endif