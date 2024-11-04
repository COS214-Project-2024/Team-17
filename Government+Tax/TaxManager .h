#ifndef TAXMANAGER _H
#define TAXMANAGER _H

class TaxManager_ {

private:
	TaxCommand* command;

public:
	void setCommand(TaxCommand* cmd);

	void executeCommand();
};

#endif
