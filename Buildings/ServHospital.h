#ifndef SERVHOSPITAL_H
#define SERVHOSPITAL_H

#include "Services.h"
class ServHospital :public Services {
private:
	int visitors;
    bool operational; // CS State
    string type = "Service Hospital";
    
public:
	ServHospital();

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
};

#endif
