#ifndef COMSHOP_H
#define COMSHOP_H

#include "Commercial.h"

class ComShop : public Commercial {
public:
    ComShop();

    void displayBuildingInfo() override;

	virtual int getJobCapacity() override;
	virtual void setJobCapacity(int capacity) override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	string getBuildingType()override;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
    int jobCapacity;
	string type = "Commercial Shop";
	bool operational;//CS State
};

#endif
