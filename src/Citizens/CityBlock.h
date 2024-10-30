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
	CityBlock(CityMediator *mediator);

	virtual void notifyChange(std::string message) = 0;

	virtual void accept(TaxAndBudgetVisitor *visitor) = 0;
};

#endif