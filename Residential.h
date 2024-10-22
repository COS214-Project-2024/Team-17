#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

class Residential : Building {


public:
	virtual bool checkBuildRequirements() = 0;

	virtual void createBuilding() = 0;

	virtual int increasePopulation() = 0;

	virtual void affectEmotionalState() = 0;
};

#endif
