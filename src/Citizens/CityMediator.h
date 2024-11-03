#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

#include <string>

class Building;
class UtilityManager;
class RoadState;
class Citizen;
class Bus;
class Trainstation;
class TaxAndBudgetVisitor;

class CityMediator
{
public:
    virtual void registerBuilding(Building *building) = 0;

    virtual void registerUtility(UtilityManager *util) = 0;

    virtual void registerCitizen(Citizen *citizen) = 0;

    virtual void registerBus(Bus *bus) = 0;

    virtual void registerTrainStation(Trainstation *trainStation) = 0;

    virtual void notifyBuildingChange(Building *building, std::string message) = 0;

    virtual void notifyUtilityChange(UtilityManager *type, bool status, std::string message) = 0;

    virtual void notifyRoadChange(RoadState *status, std::string message) = 0;

    virtual double accept(TaxAndBudgetVisitor *visitor) = 0;

    virtual ~CityMediator() {}
};

#endif