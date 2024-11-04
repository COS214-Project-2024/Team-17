#ifndef BUILDDECORECONOMIC_H
#define BUILDDECORECONOMIC_H

#include "BuildingDecorator.h"

class BuildDecorEconomic : public BuildingDecorator {
public:
    BuildDecorEconomic(Building* b);
    virtual void displayBuildingInfo() override;
};

#endif
