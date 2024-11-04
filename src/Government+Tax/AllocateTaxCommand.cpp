#include "AllocateTaxCommand.h"

/**
 * @brief Construct a new Allocate Tax Command object.
 * 
 * @param gov Shared pointer to the government instance to which this command applies.
 * @param amt The amount of tax to allocate.
 * @param dept The department to which the tax will be allocated.
 */
AllocateTaxCommand::AllocateTaxCommand(std::shared_ptr<Government> gov, double amt, const std::string& dept)
{
    this->government = gov;  // Assign the shared pointer to the member variable
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
