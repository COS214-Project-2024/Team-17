#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

class Commercial : public Building {
public:
	virtual int getJobCapacity() = 0;
	virtual void setJobCapacity(int capacity) = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif
