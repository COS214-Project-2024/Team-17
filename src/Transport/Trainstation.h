#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "../Buildings/Building.h"

class Trainstation : public Building
{
public:
    Trainstation(int serveRange);

    void displayBuildingInfo();
    ~Trainstation();

    bool getState();
    string getBuildingType();

    bool buildingInRange(Building *building);
    bool pointInRange(int x, int y);

    bool checkBuildRequirements();

    virtual bool addEmployee(Citizen *employee);
    virtual void removeEmployee(Citizen *employee);
    virtual bool hasJob();

    virtual bool moveIn(Citizen *resident);
    virtual void moveOut(Citizen *resident);

private:
    vector<UtilityManager *> utilities;
    string name;
    CityMediator *mediator;
    bool operational; // state

    int cost = 1500;

    int woodCost = 100;
    int steelCost = 100;
    int concreteCost = 100;

    int electricityUsage = 20;
    int waterUsage = 2;

    int popIncrease = 0;

    int serveRange;
};

#endif