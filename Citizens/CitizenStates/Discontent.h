#ifndef DISCONTENT_H
#define DISCONTENT_H

#include "../CitizenState.h"

class Discontent : public CitizenState
{
public:
    std::string getName()
    {
        return "Discontent";
    }
};

#endif
