#ifndef COLLECTTAXCOMMAND _H
#define COLLECTTAXCOMMAND _H

class CollectTaxCommand_ : TaxCommand_ {

public:
	Government* government;

	void CollectTaxCommand(Government* gov);

	void execute();
};

#endif
