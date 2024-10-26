#ifndef SETTAXRATECOMMAND_H
#define SETTAXRATECOMMAND_H

#include "Government.h"
#include "TaxCommand.h"
#include <string>

class SetTaxRateCommand : public TaxCommand {
private:
	Government* government;
	double taxRate;
	std::string category;
public:
	SetTaxRateCommand(Government* gov, double rate, std::string cat);
	void execute();
};

#endif
