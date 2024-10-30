#ifndef DISCONTENT_H
#define DISCONTENT_H

#include "../CitizenState.h"

class Discontent : public CitizenState
{
public:
    void handleChange();
    std::string getState();
    ~Discontent() {};
};

#endif
