#ifndef SERVEDUCATION_H
#define SERVEDUCATION_H

#include "Services.h"

class ServEducation : public Services {
public:
	ServEducation();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// void Primary();
	// void Secondary();
	// void Tertiary();

	//Observer
	void callUtilities()override;//call Utilities in Buildings
	bool getState()override;
	void setState(bool state)override;
	std::string getBuildingType()override;

private:
	int visitors;
	std::string type="Service Education";
	bool operational;//CS State
};

#endif
