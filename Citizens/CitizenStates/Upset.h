#ifndef UPSET_H
#define UPSET_H

#include "../CitizenState.h"

class Upset : public CitizenState
{
public:
    void handleChange();
    std::string getState();
    ~Upset() {};
};

#endif
