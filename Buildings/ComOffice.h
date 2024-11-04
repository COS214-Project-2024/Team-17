#ifndef COMOFFICE_H
#define COMOFFICE_H

#include "Commercial.h"

class ComOffice : public Commercial {
public:
    ComOffice();

    void displayBuildingInfo() override;

	virtual int getJobCapacity() override;
	virtual void setJobCapacity(int capacity) override;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
    int jobCapacity;
};

#endif
