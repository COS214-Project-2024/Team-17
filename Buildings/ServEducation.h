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

private:
	int visitors;
};

#endif
