#include "CitizenTaxAB.h"
#include "../Citizens/Citizen.h"
#include "../Buildings/Building.h"

double CitizenTaxAB::visit(Citizen *citizen)
{
  if(!citizen)
  {
    return 0;
  }
  return citizen->getTax();
}

double CitizenTaxAB::visit(Building *business)
{
  // return business->getTax();
  return 0;
}
