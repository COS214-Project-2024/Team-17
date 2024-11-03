#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

class Landmark : public Building {
public:
	virtual int getVisitors() = 0;
	virtual void setVisitors(int visitors) = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual void createBuilding() = 0;
	// virtual void affectEmotionalState() = 0;

private:
	int visitors;
};

#endif
