#ifndef BUILDING_H
#define BUILDING_H

#include "../../colours.h" // Testing colours and other includes
#include "../Utilities/UtilityManager.h"
#include "../Citizens/CityMediator.h"
#include "../Citizens/CityBlock.h"

#include "../resources.h"

class CityMediator;
class UtilityManager;

class Building : public CityBlock
{
public:
    Building();
    Building(CityMediator* mediator, string type);

    virtual void displayBuildingInfo() = 0;
    virtual ~Building() = default;

    virtual bool getState() = 0;
    virtual string getBuildingType();

    virtual bool checkBuildRequirements() = 0;


    void notifyChange(std::string message);
	void accept(TaxAndBudgetVisitor *visitor);

private:
    vector<UtilityManager *> utilities;
    string name;
	CityMediator* mediator;
	bool operational; //state
};

#endif // BUILDING_H

////// EVERYTHING BELOW IS FROM VP - IT IS SUBJECT TO CHANGE //////

// #ifndef BUILDING_H
// #define BUILDING_H

// class Building : UtilityObserver, CityBlock {

// private:
// 	string name;
// 	CityMediator* mediator;

// 	virtual bool checkBuildRequirements() = 0;

// public:
// 	virtual void createBuilding() = 0;

// 	void update(string& utilityStatus);

// 	void receiveElectricity();

// 	void receiveWater();

// 	void removeWaste();

// 	void removeSewage();

// 	void notifyOutage(string& utility);

// 	void notifyNoWater(string& utility);

// 	void notifyWasteRemove(string& utility);

// 	void notifySewageRemove(string& utility);

// 	virtual void affectEmotionalState() = 0;

// 	Building(CityMediator* mediator, string type);

// 	string getType();

// 	void construct();

// 	void abstract_notifyChange();

// 	void accept(TaxAndBudgetVisitor* visitor);
// };

// #endif
