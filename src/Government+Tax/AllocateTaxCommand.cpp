#include "AllocateTaxCommand.h"

AllocateTaxCommand::AllocateTaxCommand(Government *gov, double amt, std::string dept)
{
  this->government = gov;
  this->amount = amt;
  this->department = dept;
}

void AllocateTaxCommand::execute()
{
  this->government->allocateTaxes(this->department, this->amount);
}
