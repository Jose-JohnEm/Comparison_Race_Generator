#include "crg.hpp"

specs::specs()
{

}

specs::~specs()
{

}

void specs::setUnit(std::string unit)
{
    sUnit = unit;
}

void specs::setTimes(std::vector<std::string> times)
{
    sTimes = times;
}