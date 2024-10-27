#include "CityStructure.h"

CityStructure::CityStructure(std::string name)
{
  this->Name = name;
}

void CityStructure::accept(TaxAndBudgetVisitor* visitor) {
	// TODO - implement CityStructure::accept
	throw "Not yet implemented";
}

void CityStructure::addBlock(CityBlock* block) {
  this->blocks.push_back(block);
}

double CityStructure::getIncome() {
  // maybe instead of building size do citizens?
  return 50 * this->blocks.size();
}

void CityStructure::allocateBudget(std::string deparment , double amount)
{
  this->departments[deparment] += amount;
}

std::string CityStructure::getName()
{
  return this->Name;
}
