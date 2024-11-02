#ifndef DISCONTENT_H
#define DISCONTENT_H

#include "../CitizenState.h"

class Discontent : public CitizenState
{
public:
    CitizenState *handleChange(int change);
    std::string getState();
    ~Discontent() {};
};

#endif
