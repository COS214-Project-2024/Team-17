#ifndef SERVICES_H
#define SERVICES_H

class Services : Building {


public:
	virtual bool checkBuildRequirements() = 0;

	virtual void createBuilding() = 0;

	virtual void affectEmotionalState() = 0;
};

#endif
