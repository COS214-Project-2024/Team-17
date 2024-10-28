#ifndef CONTENT_H
#define CONTENT_H

#include "../CitizenState.h"

class Content : public CitizenState
{
public:
    std::string getName()
    {
        return "Content";
    }
};

#endif
