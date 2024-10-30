#include "AllocateTaxCommand.h"
#include <iostream>

AllocateTaxCommand::AllocateTaxCommand(Government *gov, double amt, std::string dept)
{
  this->government = gov;
  this->amount = amt;
  this->department = dept;
}

void AllocateTaxCommand::execute()
{
  std::cout << "executing allocate tax\n";
  this->government->allocateTaxes(this->department, this->amount);
}
