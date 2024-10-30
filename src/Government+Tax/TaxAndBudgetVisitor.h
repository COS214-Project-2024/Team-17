#ifndef TAXANDBUDGETVISITOR_H
#define TAXANDBUDGETVISITOR_H

#include "Government.h"
class Building;
class Citizen;

class TaxAndBudgetVisitor : public Government
{
public:
	virtual double visit(Citizen *citizen) = 0;
	virtual double visit(Building *business) = 0;
	virtual ~TaxAndBudgetVisitor() {}
};

#endif
