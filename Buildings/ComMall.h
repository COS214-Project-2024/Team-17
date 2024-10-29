#ifndef COMMALL_H
#define COMMALL_H

#include "Commercial.h"
#include <iostream>
class ComMall : public Commercial {
public:
    ComMall();

    void displayBuildingInfo() override;

	int getJobCapacity() override;
	void setJobCapacity(int capacity) override;
//Observer
	void callUtilities()override;//call Utilities in Buildings
	bool getState()override;
	void setState(bool state)override;
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;


	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
    int jobCapacity;
	std::string type="Commercial Mall";
	bool operational;//CS State
};

#endif
