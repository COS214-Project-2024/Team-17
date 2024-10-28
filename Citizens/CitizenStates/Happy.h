#ifndef HAPPY_H
#define HAPPY_H

#include "../CitizenState.h"

class Happy : public CitizenState
{
public:
    std::string getName()
    {
        return "Happy";
    }
};

#endif
