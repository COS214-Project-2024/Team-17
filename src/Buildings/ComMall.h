#ifndef COMMALL_H
#define COMMALL_H

#include "Commercial.h"

class ComMall : public Commercial {
public:
    ComMall();

    void displayBuildingInfo() override;

	virtual int getJobCapacity() override;
	virtual void setJobCapacity(int capacity) override;

	// Observer
	void callUtilities(); //call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType();

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
    int jobCapacity;
	string type = "Commercial Mall";
	bool operational; //CS State
};

#endif