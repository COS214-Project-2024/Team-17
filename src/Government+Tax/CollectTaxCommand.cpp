#include "CollectTaxCommand.h"
#include <iostream>
/**
 * @brief Construct a new CollectTaxCommand object.
 * 
 * @param gov Pointer to the Government instance.
 */
CollectTaxCommand::CollectTaxCommand(std::shared_ptr<Government> gov)
{
    this->government = gov; // Initialize the shared pointer
}
/**
 * @brief Execute the command to collect taxes for the government.
 */
void CollectTaxCommand::execute()
{
    if (government) {
        government->collectTaxes(); // Assuming Government has a collectTaxes() method
    }
}
