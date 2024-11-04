#ifndef ALLOCATETAXCOMMAND _H
#define ALLOCATETAXCOMMAND _H

class AllocateTaxCommand_ : TaxCommand_ {

private:
	Government* government;
	double amount;
	string department;

public:
	void AllocateTaxCommand(Government* gov, double amt, string dept);

	void execute();
};

#endif
