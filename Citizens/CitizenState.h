#ifndef CITIZENSTATE_H
#define CITIZENSTATE_H

#include <string>

class CitizenState
{
public:
    virtual std::string getName() = 0;
    ~CitizenState() {}
};

#endif
