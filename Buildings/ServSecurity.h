#ifndef SERVSECURITY_H
#define SERVSECURITY_H

#include "Services.h"

class ServSecurity : public Services {
public:
	ServSecurity();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// void Police();
	// void Firestation();

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;

private:
	int visitors;
	bool operational;//CS State
	std::string type="Service Security";
};

#endif
