#ifndef SERVENTERTAINMENT_H
#define SERVENTERTAINMENT_H

#include "Services.h"

class ServEntertainment : public Services {
public:
	ServEntertainment();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	string getBuildingType();

	// void Movie();
	// void Arcade();
	// void Gym();

private:
	int visitors;
	string type="Service Entertainment";
	bool operational;//CS State
};

#endif
