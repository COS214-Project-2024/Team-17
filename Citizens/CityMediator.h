#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

#include "../Buildings/Building.h"
#include "../Transport/RoadComponent.h"
#include "../Utilities/UtilityManager.h"


class CityMediator {
public:
    virtual void registerBuilding(Building* building) = 0;
    virtual void registerUtility(UtilityManager* util) = 0;
    virtual void notifyBuildingChange(Building* building) = 0;
    virtual void notifyUtilityChange(UtilityManager* type, bool status) = 0;
    virtual void notifyRoadChange(RoadComponent* status) = 0;
};

#endif
