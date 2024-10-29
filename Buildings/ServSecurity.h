#ifndef SERVSECURITY_H
#define SERVSECURITY_H

#include "Services.h"

class ServSecurity : public Services {
public:
	ServSecurity();

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
	std::string getBuildingType();

	// void Police();
	// void Firestation();

private:
	int visitors;
	bool operational;//CS State
	string type="Service Security";
};

#endif
