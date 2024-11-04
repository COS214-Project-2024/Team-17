#ifndef RESESTATE_H
#define RESESTATE_H

#include "Residential.h"

class ResEstate : public Residential
{
public:
    ResEstate();
    ~ResEstate();

    void displayBuildingInfo() override;

    int getCapacity() const override;
    void setCapacity(int capacity) override;

    // Observer
    void callUtilities(); // call Utilities in Buildings
    bool getState();
    void setState(bool state);
    std::string getBuildingType();

    void notifyEmployeeLeft(Citizen *employee) override;
    bool moveIn(Citizen *resident);
    void moveOut(Citizen *resident);

    int getElectricityUsage();
    int getWaterUsage();
    int getCurCitizenCount();

private:
    int capacity;
    string type = "Residential Estate";
    bool operational; // CS State

    vector<Citizen *> residents;
    // Resources
    int cost = 4000;

    int woodCost = 20;
    int steelCost = 20;
    int concreteCost = 20;

    int electricityUsage = 20;
    int waterUsage = 20;

    int popIncrease = 50;
};

#endif // RESESTATE_H
