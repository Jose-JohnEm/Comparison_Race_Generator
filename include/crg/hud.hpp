#include "crg/company.hpp"
#include "crg/specs.hpp"

#ifndef __HUD__
#define __HUD__

class HUD
{
    public:
        HUD();
        ~HUD();

        void init(specs specifications, Companies comps);

    private:
        specs hInfo;
        Companies hComp;
};

#endif