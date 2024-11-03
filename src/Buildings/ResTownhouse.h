#ifndef RESTOWNHOUSE_H
#define RESTOWNHOUSE_H

#include "Residential.h"

class ResTownhouse : public Residential
{
public:
    ResTownhouse();
    ~ResTownhouse();

    void displayBuildingInfo() override;

    int getCapacity() const override;
    void setCapacity(int capacity) override;

    // Observer
    void callUtilities(); // call Utilities in Buildings
    bool getState();
    void setState(bool state);

    std::string getBuildingType();

    void notifyEmployeeLeft(Citizen *employee);

    bool moveIn(Citizen *resident);
    void moveOut(Citizen *resident);

private:
    int capacity;
    string type = "Residential Townhouse";
    bool operational; // CS State

    vector<Citizen *> residents;
    // Resources
    int cost = 1500;

    int woodCost = 10;
    int steelCost = 10;
    int concreteCost = 15;

    int electricityUsage = 10;
    int waterUsage = 10;

    int popIncrease = 10;
};

#endif // RESTOWNHOUSE_H
