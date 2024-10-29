#ifndef INDIFFERENT_H
#define INDIFFERENT_H

#include "../CitizenState.h"

class Indifferent : public CitizenState
{
public:
    void handleChange();
    std::string getState();
    ~Indifferent() {};
};

#endif
