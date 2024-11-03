#ifndef HAPPY_H
#define HAPPY_H

#include "../CitizenState.h"

class Happy : public CitizenState
{
public:
    CitizenState *handleChange(int change);
    std::string getState();
    ~Happy() {};
};

#endif
