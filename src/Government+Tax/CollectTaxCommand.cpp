#include "CollectTaxCommand.h"
#include <iostream>
/**
 * @brief Construct a new CollectTaxCommand object.
 * 
 * @param gov Pointer to the Government instance.
 */
CollectTaxCommand::CollectTaxCommand(Government *gov)
{
  this->government = gov;
}
/**
 * @brief Execute the command to collect taxes for the government.
 */
void CollectTaxCommand::execute()
{
  this->government->collectTaxes();
}
