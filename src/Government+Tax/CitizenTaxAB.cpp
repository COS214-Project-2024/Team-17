#include "CitizenTaxAB.h"
#include "../Citizens/Citizen.h"
#include "../Buildings/Building.h"

/**
 * @brief Visit a Citizen and calculate the tax.
 * 
 * @param citizen Shared pointer to the Citizen being visited.
 * @return Tax amount for the given citizen. Returns 0 if the citizen is null.
 */
double CitizenTaxAB::visit(std::shared_ptr<Citizen> citizen)
{
    if (!citizen) // Check if the shared pointer is valid
    {
        return 0;
    }
    return citizen->getTax(); // Call getTax() on the Citizen instance
}

/**
 * @brief Visit a Building and calculate the tax.
 * 
 * @param business Shared pointer to the Building being visited.
 * @return Tax amount for the given building.
 */
double CitizenTaxAB::visit(std::shared_ptr<Building> business)
{
    if (!business) // Check if the shared pointer is valid
    {
        return 0;
    }
    return business->getTax(); // Call getTax() on the Building instance
}
