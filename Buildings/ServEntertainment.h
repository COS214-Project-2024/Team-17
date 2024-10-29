#ifndef SERVENTERTAINMENT_H
#define SERVENTERTAINMENT_H

#include "Services.h"

class ServEntertainment : public Services {
public:
	ServEntertainment();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// void Movie();
	// void Arcade();
	// void Gym();

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	std::string getBuildingType()override;

private:
	int visitors;
	std::string type="Service Entertainment";
	bool operational;//CS State
};

#endif
