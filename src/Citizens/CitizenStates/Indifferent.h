#ifndef INDIFFERENT_H
#define INDIFFERENT_H

#include "../CitizenState.h"

class Indifferent : public CitizenState
{
public:
    CitizenState *handleChange(int change);
    std::string getState();
    ~Indifferent() {};
};

#endif
