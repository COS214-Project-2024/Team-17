#ifndef SERVICES_H
#define SERVICES_H

#include "Building.h"

class Services : public Building {
public:
	virtual int getVisitors() = 0;
	virtual void setVisitors(int visitors) = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual void createBuilding() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif
