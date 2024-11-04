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

private:
	int visitors;
};

#endif
