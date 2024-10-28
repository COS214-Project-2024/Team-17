#ifndef INDIFFERENT_H
#define INDIFFERENT_H

#include "../CitizenState.h"

class Indifferent : public CitizenState
{
public:
    std::string getName()
    {
        return "Indifferent";
    }
};

#endif
