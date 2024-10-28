#include "CollectTaxCommand.h"
#include <iostream>

CollectTaxCommand::CollectTaxCommand(Government* gov) {
  this->government = gov;
}

void CollectTaxCommand::execute() { 
  std::cout << "executing collect taxes\n";
  this->government->collectTaxes();
}
