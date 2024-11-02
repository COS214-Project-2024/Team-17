#ifndef CONTENT_H
#define CONTENT_H

#include "../CitizenState.h"

class Content : public CitizenState
{
public:
    CitizenState *handleChange(int change);
    std::string getState();
    ~Content() {};
};

#endif
