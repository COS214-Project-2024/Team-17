#ifndef TAXANDBUDGETVISITOR_H
#define TAXANDBUDGETVISITOR_H

class TaxAndBudgetVisitor : Government {


public:
	virtual void visit(Citizen* citizen) = 0;

	virtual void visit(Business* business) = 0;
};

#endif
