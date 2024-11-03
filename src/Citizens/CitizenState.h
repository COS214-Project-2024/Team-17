#ifndef CITIZENSTATE_H
#define CITIZENSTATE_H

#include <string>

class CitizenState
{
public:
    virtual CitizenState *handleChange(int change) = 0;
    virtual std::string getState() = 0;
    virtual ~CitizenState() {};
};

#endif
