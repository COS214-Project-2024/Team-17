#ifndef CITYBLOCK_H
#define CITYBLOCK_H

#include "CityMediator.h"
#include <string>

class TaxAndBudgetVisitor;

class CityBlock
{

protected:
	CityMediator *mediator;

public:
	CityBlock();

	virtual void notifyChange(std::string message) = 0;

	double accept(TaxAndBudgetVisitor *visitor);
};

#endif