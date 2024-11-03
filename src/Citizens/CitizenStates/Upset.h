#ifndef UPSET_H
#define UPSET_H

#include "../CitizenState.h"

class Upset : public CitizenState
{
public:
    CitizenState *handleChange(int change);
    std::string getState();
    ~Upset() {};
};

#endif
