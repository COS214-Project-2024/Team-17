#ifndef GOVERNMENT_H
#define GOVERNMENT_H

class Government {


public:
	void processTaxes(CityStructure& city);

	void applyBudget(CityStructure& city);

	void setTaxRate(string category, double rate);

	void collectTaxes();

	void allocateTaxes(string department, double amount);

private:
	TaxHandler* createTaxHandlerChain();
};

#endif
