#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

class Building;
class Utilities;
class RoadState;

class CityMediator
{
public:
    virtual void registerBuilding(Building *building) = 0;

    virtual void registerUtility(Utilities *util) = 0;

    virtual void notifyBuildingChange(Building *building) = 0;

    virtual void notifyUtilityChange(Utilities *type, bool status) = 0;

    virtual void notifyRoadChange(RoadState *status) = 0;
};

#endif
