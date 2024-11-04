#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"

class Industrial : public Building {
public:
	virtual int getProductionCapacity() = 0;
	virtual void setProductionCapacity(int capacity) = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif