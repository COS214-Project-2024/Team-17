#ifndef BUILDING_H
#define BUILDING_H

#include "../colours.h" // Testing colours and other includes
#include "../Citizens/CityBlock.h"
#include "../Utilities/UtilityObserver.h"
#include "../Citizens/CityMediator.h"

class Building : public UtilityObserver, public CityBlock{
private:
	string name;
	CityMediator* mediator;
	virtual bool checkBuildRequirements() = 0;
	bool operational;//state
    std::vector<UtilityManager*> Utilities;


public:
    virtual void displayBuildingInfo() = 0;
    virtual ~Building() = default;
    // virtual void update(UtilityManager* unit) = 0;
    //Add virtual?
    virtual bool getState()=0;
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify

	Building(CityMediator* mediator, string type);

	void notifyChange();

};


#endif // BUILDING_H






////// EVERYTHING BELOW IS FROM VP - IT IS SUBJECT TO CHANGE //////

// #ifndef BUILDING_H
// #define BUILDING_H

// class Building : public UtilityObserver, CityBlock {

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
