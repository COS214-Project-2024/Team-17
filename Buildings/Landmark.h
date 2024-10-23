#ifndef LANDMARK_H
#define LANDMARK_H

class Landmark : Building {


public:
	virtual bool checkBuildRequirements() = 0;

	virtual void createBuilding() = 0;

	virtual void affectEmotionalState() = 0;
};

#endif
