#ifndef CITYBLOCK_H
#define CITYBLOCK_H

#include "CityMediator.h"
#include <string>

class TaxAndBudgetVisitor;

class CityBlock
{

protected:
	CityMediator *mediator = nullptr;

public:
	CityBlock();

	double accept(TaxAndBudgetVisitor *visitor);
};

#endif