#include "CityStructure.h"

#include "TaxAndBudgetVisitor.h"
#include "../Citizens/Citizen.h"
#include "../Citizens/CityBlock.h"
#include "../Buildings/Building.h"

#include <iostream>
/**
 * @brief Construct a new CityStructure object.
 * 
 * @param name Name of the city structure.
 */
CityStructure::CityStructure(std::string name)
{
  this->Name = name;
  this->income = 0;
}
/**
 * @brief Accepts a visitor for the CityStructure.
 * 
 * @param visitor Pointer to the visitor object to be accepted.
 */
void CityStructure::accept(TaxAndBudgetVisitor *visitor)
{
  for(CityBlock* block : blocks) {
    this->income += block->accept(visitor);
  }
}
/**
 * @brief Adds a block to the CityStructure.
 * 
 * @param block Pointer to the CityBlock to add.
 */
void CityStructure::addBlock(CityBlock *block)
{
  this->blocks.push_back(block);
}
/**
 * @brief Gets the income of the CityStructure.
 * 
 * @return Total income of the CityStructure.
 */
double CityStructure::getIncome()
{
  // maybe instead of building size do citizens?
  return this->income;
}
/**
 * @brief Allocates a budget amount to a department.
 * 
 * @param department Name of the department.
 * @param amount Budget amount to allocate.
 */
void CityStructure::allocateBudget(std::string deparment, double amount)
{
  this->departments[deparment] += amount;
}
/**
 * @brief Gets the name of the CityStructure.
 * 
 * @return Name of the CityStructure.
 */
std::string CityStructure::getName()
{
  return this->Name;
}
