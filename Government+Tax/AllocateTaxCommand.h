#ifndef ALLOCATETAXCOMMAND_H
#define ALLOCATETAXCOMMAND_H

#include "TaxCommand.h"

class Government;

#include <string>

class AllocateTaxCommand : public TaxCommand {

private:
	Government* government;
	double amount;
	std::string department;

public:
	AllocateTaxCommand(Government* gov, double amt, std::string dept);
	void execute();
};

#endif
