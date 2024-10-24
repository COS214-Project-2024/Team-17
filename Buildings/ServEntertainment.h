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

private:
	int visitors;
};

#endif
