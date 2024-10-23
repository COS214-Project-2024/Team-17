#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

class Industrial : Building {


public:
	virtual bool checkBuildRequirements() = 0;

	virtual void createBuilding() = 0;

	virtual void increaseJobs() = 0;

	virtual void affectEmotionalState() = 0;
};

#endif
