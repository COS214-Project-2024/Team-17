#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <iostream>
class Residential : public Building {
	private:
	bool operational;//CS State
	std::string type;
public:
	virtual int getCapacity() const = 0;
	virtual void setCapacity(int capacity) = 0;
//Observer
	virtual void callUtilities();//call Utilities in Buildings
	virtual bool getState();
	virtual void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	virtual std::string getBuildingType();

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif // RESIDENTIAL_H