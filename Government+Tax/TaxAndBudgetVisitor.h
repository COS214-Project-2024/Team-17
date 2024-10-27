#ifndef TAXANDBUDGETVISITOR_H
#define TAXANDBUDGETVISITOR_H

#include "Government.h"
#include "Building.h"
#include "Citizen.h"

class TaxAndBudgetVisitor : public Government {
public:
	virtual void visit(Citizen* citizen) = 0;
	virtual void visit(Building* business) = 0;
  virtual ~TaxAndBudgetVisitor() {}
};

#endif
