#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

#include <string>

class Building;
class Utilities;
class RoadState;
class Citizen;

class CityMediator
{
public:
    virtual void registerBuilding(Building *building) = 0;

    virtual void registerUtility(Utilities *util) = 0;

    virtual void registerCitizen(Citizen *citizen) = 0;

    virtual void notifyBuildingChange(Building *building, std::string message) = 0;

    virtual void notifyUtilityChange(Utilities *type, bool status, std::string message) = 0;

    virtual void notifyRoadChange(RoadState *status, std::string message) = 0;

    virtual ~CityMediator() {}
};

#endif