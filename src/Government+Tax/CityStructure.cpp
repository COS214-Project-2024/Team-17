#include "CityStructure.h"
#include "TaxAndBudgetVisitor.h"
#include "../Citizens/Citizen.h"

#include <iostream>

CityStructure::CityStructure(std::string name)
{
  this->Name = name;
  this->income = 0;
}

void CityStructure::accept(TaxAndBudgetVisitor *visitor)
{
  std::cout << "Visiting all Citizens and Buildings/Bussinesses in citystructure\n";
  // visitor->visit(new Citizen());
  // visitor->visit(new Building());
  // for(CityBlock* block : blocks) {
  //   for(Building* buildings : block.getBuildings()) {
  //       this->income += visitor->visit(buildings);
  //       for(Citizen* citizen : buildings.getResidence())
  //       {
  //         this->income += visitor->visit(citizen);
  //       }
  //   }
  // }
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
