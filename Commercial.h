#ifndef COMMERCIAL_H
#define COMMERCIAL_H

class Commercial : Building {


public:
	virtual bool checkBuildRequirements() = 0;

	virtual void createBuilding() = 0;

	virtual void increaseJobs() = 0;

	virtual void affectEmotionalState() = 0;

	void operation();
};

#endif
