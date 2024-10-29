#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "TaxCommand.h"

class TaxManager
{
private:
	TaxCommand *command = nullptr;

public:
	void setCommand(TaxCommand *cmd);
	void executeCommand();
};

#endif
