#ifndef CONGESTED_H
#define CONGESTED_H

#include "../RoadState.h"

class Congested : public RoadState
{
public:
    virtual void handleTraffic(RoadComponent *road);

    virtual std::string getStatus();
};

#endif
