#ifndef BUILDING_H
#define BUILDING_H

#include "../../colours.h" // Testing colours and other includes
#include "../Utilities/UtilityManager.h"
#include "../Citizens/CityMediator.h"
#include "../Citizens/CityBlock.h"

#include "../Citizens/Citizen.h"

#include "../resources.h"
#include "BuildingRequirements.h"

class CityMediator;
class UtilityManager;

class Building : public CityBlock
{
public:
    Building(string type = "");

    virtual void displayBuildingInfo() = 0;
    virtual ~Building() = default;

    virtual bool getState() = 0;
    virtual string getBuildingType();

    virtual bool checkBuildRequirements() = 0;

    void notifyChange(std::string message);
    void accept(TaxAndBudgetVisitor *visitor);

    int getXCordinate();
    int getYCordinate();

    void setXCordinate(int x);
    void setYCordinate(int y);

private:
    vector<UtilityManager *> utilities;
    string name;
    CityMediator *mediator;
    bool operational; // state

protected:
    int xCoordinate;
    int yCoordinate;
};

#endif // BUILDING_H