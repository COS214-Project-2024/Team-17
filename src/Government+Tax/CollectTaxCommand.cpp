#include "CollectTaxCommand.h"
#include <iostream>

CollectTaxCommand::CollectTaxCommand(Government *gov)
{
  this->government = gov;
}

void CollectTaxCommand::execute()
{
  this->government->collectTaxes();
}
