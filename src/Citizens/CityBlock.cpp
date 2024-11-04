#include "CityBlock.h"
#include "CityCentralMediator.h"
#include <iostream>

CityBlock::CityBlock()
{
	this->mediator = CityCentralMediator::getInstance();
}

double CityBlock::accept(TaxAndBudgetVisitor *visitor)
{  
  if(mediator)
  {
    return mediator->accept(visitor);
  }
  return 0;
}
