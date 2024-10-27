#ifndef CITIZENTAXAB_H
#define CITIZENTAXAB_H

#include "TaxAndBudgetVisitor.h"

class CitizenTaxAB : public TaxAndBudgetVisitor {
public:
	void visit(Citizen* citizen);
	void visit(Building* business);
};

#endif
