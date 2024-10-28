#ifndef CITIZENTAXAB_H
#define CITIZENTAXAB_H

#include "TaxAndBudgetVisitor.h"

class CitizenTaxAB : public TaxAndBudgetVisitor {
public:
	double visit(Citizen* citizen);
	double visit(Building* business);
};

#endif
