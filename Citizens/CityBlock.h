#ifndef CITYBLOCK_H
#define CITYBLOCK_H

#include "CityMediator.h"
class TaxAndBudgetVisitor;

class CityBlock
{

protected:
	CityMediator *mediator;

public:
	CityBlock(CityMediator *mediator);

	virtual void notifyChange() = 0;

	virtual void accept(TaxAndBudgetVisitor *visitor) = 0;
};

#endif
