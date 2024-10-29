#ifndef INDFACTORY_H
#define INDFACTORY_H

#include "Industrial.h"

class IndFactory : public Industrial {
public:
    IndFactory();

    void displayBuildingInfo() override;

    int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

    //Observer
	void callUtilities();
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	string getBuildingType() override;

	// virtual bool checkBuildRequirements() override;
	// virtual void increaseJobs() override;
	// virtual void affectEmotionalState() override;

private:
    int productionCapacity;
    string type = "Industrial Factory";
    bool operational;//CS State
};

#endif
