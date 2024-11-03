#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"

class UtilityManager;

class Commercial : public Building
{
public:
	virtual int getJobCapacity() = 0;
	virtual void setJobCapacity(int capacity) = 0;

	virtual bool getState();
	virtual string getBuildingType();
	bool checkBuildRequirements() override;

	// Observer pattern
	void addUtility(UtilityManager *utility);	 // attach
	void removeUtility(UtilityManager *utility); // detach
	void notifyUtilities();						 // notify

	virtual bool addEmployee(Citizen *employee) = 0;
	virtual void removeEmployee(Citizen *employee) = 0;
	virtual void notifyEmployeeLeft(Citizen *employee) = 0;

	virtual bool moveIn(Citizen *resident);
	virtual void moveOut(Citizen *resident);

	virtual int getElectricityUsage() = 0;
	virtual int getWaterUsage() = 0;
	virtual int getCurCitizenCount() = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
	bool operational; // part of Observer
	vector<UtilityManager *> Utilities;
};

#endif
