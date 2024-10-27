#ifndef COLLECTTAXCOMMAND_H
#define COLLECTTAXCOMMAND_H

#include "TaxCommand.h"
#include "Government.h"

class CollectTaxCommand : public TaxCommand {

private:
	Government* government;
public:
	CollectTaxCommand(Government* gov);
	void execute();
};

#endif
