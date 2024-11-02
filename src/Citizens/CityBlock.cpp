#include "CityBlock.h"
#include "CityCentralMediator.h"

CityBlock::CityBlock()
{
	this->mediator = CityCentralMediator::getInstance();
}
