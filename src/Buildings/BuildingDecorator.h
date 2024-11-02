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

    
    virtual bool addEmployee(Citizen* employee);
	virtual void removeEmployee(Citizen* employee);

    virtual bool moveIn(Citizen* resident);
    virtual void moveOut(Citizen* resident);
};

#endif