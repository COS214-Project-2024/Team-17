#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

class Residential : public Building
{
public:
	virtual int getCapacity() const = 0;
	virtual void setCapacity(int capacity) = 0;

	bool checkBuildRequirements() override;

	// Observer
	virtual bool getState() = 0;
	virtual std::string getBuildingType() = 0;
	void addUtility(UtilityManager *utility);	 // attach
	void removeUtility(UtilityManager *utility); // detach
	void notifyUtilities();						 // notify

	virtual bool addEmployee(Citizen *employee);
	virtual void removeEmployee(Citizen *employee);
	virtual bool hasJob();

	virtual bool moveIn(Citizen *resident) = 0;
	virtual void moveOut(Citizen *resident) = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;

private:
	bool operational; // state
	vector<UtilityManager *> Utilities;
};

#endif // RESIDENTIAL_H