#include "CitizenTaxAB.h"
#include "../Citizens/Citizen.h"
#include "../Buildings/Building.h"

double CitizenTaxAB::visit(Citizen *citizen)
{
  return citizen->getTax();
}

double CitizenTaxAB::visit(Building *business)
{
  // return business->getTax();
}
