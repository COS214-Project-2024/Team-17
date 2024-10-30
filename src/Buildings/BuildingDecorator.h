#ifndef BUILDINGDECORATOR_H
#define BUILDINGDECORATOR_H

#include "Building.h"

class BuildingDecorator : public Building {
protected:
    Building* building;

public:
    BuildingDecorator(Building* b);
    virtual void displayBuildingInfo() override;
    virtual ~BuildingDecorator();

    bool checkBuildRequirements() override;
    bool getState() override;
};

#endif