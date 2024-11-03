#include "CityStructure.h"

#include "TaxAndBudgetVisitor.h"
#include "../Citizens/Citizen.h"
#include "../Citizens/CityBlock.h"
#include "../Buildings/Building.h"

#include <iostream>

CityStructure::CityStructure(std::string name)
{
  this->Name = name;
  this->income = 0;
}

void CityStructure::accept(TaxAndBudgetVisitor *visitor)
{
  for(CityBlock* block : blocks) {
    block->accept(visitor);
  }
}

void CityStructure::addBlock(CityBlock *block)
{
  this->blocks.push_back(block);
}

double CityStructure::getIncome()
{
  // maybe instead of building size do citizens?
  return this->income;
}

void CityStructure::allocateBudget(std::string deparment, double amount)
{
  this->departments[deparment] += amount;
}

std::string CityStructure::getName()
{
  return this->Name;
}
