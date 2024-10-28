#ifndef UPSET_H
#define UPSET_H

#include "../CitizenState.h"

class Upset : public CitizenState
{
public:
    std::string getName()
    {
        return "Upset";
    }
};

#endif
