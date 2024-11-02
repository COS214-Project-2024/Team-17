#include "CityBlock.h"
#include "CityCentralMediator.h"

CityBlock::CityBlock()
{
	this->mediator = CityCentralMediator::getInstance();
}

double CityBlock::accept(TaxAndBudgetVisitor *visitor)
{
  return this->mediator->accept(visitor);
}
