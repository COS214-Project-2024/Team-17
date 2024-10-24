#ifndef WORKINGNOISSUES_H
#define WORKINGNOISSUES_H

#include "RoadState.h"

class WorkingNoIssues : public RoadState
{
public:
    virtual void handleTraffic(RoadComponent *road);

    virtual std::string getStatus();
};

#endif
