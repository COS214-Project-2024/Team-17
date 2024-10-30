#ifndef SERVEDUCATION_H
#define SERVEDUCATION_H

#include "Services.h"

class ServEducation : public Services {
public:
	ServEducation();

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

	// void Primary();
	// void Secondary();
	// void Tertiary();

private:
	int visitors;
	string type="Service Education";
	bool operational;//CS State
};

#endif
