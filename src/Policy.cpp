#include "Policy.h"

bool Policy::busLaw = false;
bool Policy::happinessLaw = false;
bool Policy::moneyLaw = false;
bool Policy::noTaxLaw = false;
bool Policy::servicesLaw = false;

void Policy::setBusLaw(bool value)
{
  busLaw = value;
}

bool Policy::getBusLaw()
{
  return busLaw;
}

void Policy::setHappinessLaw(bool value)
{
  happinessLaw = value;
}

bool Policy::getHappinessLaw()
{
  return happinessLaw;
}

void Policy::setMoneyLaw(bool value)
{
  moneyLaw = value;
}

bool Policy::getMoneyLaw()
{
  return moneyLaw; 
}

void Policy::setNoTaxLaw(bool value)
{
  noTaxLaw = value;
}

bool Policy::getNoTaxLaw()
{
  return noTaxLaw;
}

void Policy::setServicesLaw(bool value)
{
  servicesLaw = value;
}

bool Policy::getServicesLaw()
{
  return servicesLaw; 
}