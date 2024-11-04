#include "CitizenTaxAB.h"
#include "../Citizens/Citizen.h"
#include "../Buildings/Building.h"
/**
 * @brief Visit a Citizen and calculate the tax.
 * 
 * @param citizen Pointer to the Citizen being visited.
 * @return Tax amount for the given citizen. Returns 0 if the citizen is null.
 */
double CitizenTaxAB::visit(Citizen *citizen)
{
  return citizen->getTax();
}
/**
 * @brief Visit a Building and calculate the tax.
 * 
 * @param business Pointer to the Building being visited.
 * @return Tax amount for the given building.
 */
double CitizenTaxAB::visit(Building *business)
{
  return business->getTax();
}
