#include "AllocateTaxCommand.h"
/**
 * @brief Construct a new Allocate Tax Command object.
 * 
 * @param gov Pointer to the government instance to which this command applies.
 * @param amt The amount of tax to allocate.
 * @param dept The department to which the tax will be allocated.
 */
AllocateTaxCommand::AllocateTaxCommand(Government *gov, double amt, std::string dept)
{
  this->government = gov;
  this->amount = amt;
  this->department = dept;
}
/**
 * @brief Execute the allocate tax command, which allocates taxes to a specified department in the government.
 */
void AllocateTaxCommand::execute()
{
  this->government->allocateTaxes(this->department, this->amount);
}
