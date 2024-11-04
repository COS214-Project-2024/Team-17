#ifndef SETTAXRATECOMMAND _H
#define SETTAXRATECOMMAND _H

class SetTaxRateCommand_ : TaxCommand_ {

private:
	Government* government;
	double taxRate;
	string category;

public:
	void SetTaxRateCommand(Government* gov, double rate, string cat);

	void execute();
};

#endif
