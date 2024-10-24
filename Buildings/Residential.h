#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

class Residential : public Building {
public:
	virtual int getCapacity() const = 0;
	virtual void setCapacity(int capacity) = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif // RESIDENTIAL_H