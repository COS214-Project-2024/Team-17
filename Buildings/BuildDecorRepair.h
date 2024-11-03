#ifndef BUILDDECORREPAIR_H
#define BUILDDECORREPAIR_H

#include "BuildingDecorator.h"

class BuildDecorRepair : public BuildingDecorator {
public:
    BuildDecorRepair(Building* b);
    virtual void displayBuildingInfo() override;
};

#endif
