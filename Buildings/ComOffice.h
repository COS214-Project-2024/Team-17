#ifndef COMOFFICE_H
#define COMOFFICE_H

#include "Commercial.h"
#include <iostream>
class ComOffice : public Commercial {
public:
    ComOffice();

    void displayBuildingInfo() override;

	int getJobCapacity() override;
	void setJobCapacity(int capacity) override;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType();
private:
    int jobCapacity;
	std::string type="Commercial Office";
	bool operational;//CS State
};

#endif
