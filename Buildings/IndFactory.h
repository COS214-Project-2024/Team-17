#ifndef INDFACTORY_H
#define INDFACTORY_H

#include "Industrial.h"

class IndFactory : public Industrial {
public:
    IndFactory();

    void displayBuildingInfo() override;

    int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

	// virtual bool checkBuildRequirements() override;
	// virtual void increaseJobs() override;
	// virtual void affectEmotionalState() override;

//Observer
	void callUtilities()override;//call Utilities in Buildings
	bool getState()override;
	void setState(bool state)override;
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;

private:
    int productionCapacity;
    std::string type="Industrial Factory";
    bool operational;//CS State
};

#endif
