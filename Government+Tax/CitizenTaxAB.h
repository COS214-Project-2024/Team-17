#ifndef CITIZENTAXAB_H
#define CITIZENTAXAB_H

class CitizenTaxAB : TaxAndBudgetVisitor {


public:
	void visit(Citizen* citizen);

	void visit(Business* business);
};

#endif
