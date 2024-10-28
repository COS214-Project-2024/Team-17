#ifndef SERVHOSPITAL_H
#define SERVHOSPITAL_H

#include "Services.h"
class ServHospital :public Services {
    private:
	int visitors;
    bool operational;//CS State
    std::string type="Service Hospital";
    
    public:
		ServHospital();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;
    //Observer
	void callUtilities()override;//call Utilities in Buildings
	bool getState()override;
	void setState(bool state)override;
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;
};

#endif
