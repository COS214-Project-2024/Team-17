#ifndef INDUSTRIAL2_H
#define INDUSTRIAL2_H

class Industrial2 {


private:
	virtual bool checkBuildRequirements() = 0;

public:
	virtual void createBuilding() = 0;

	virtual void increaseJobs() = 0;

	virtual void affectEmotionalState() = 0;
};

#endif
