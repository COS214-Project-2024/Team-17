#include "CitizenTaxAB.h"
#include <iostream>

double CitizenTaxAB::visit(Citizen* citizen) {
  std::cout << "Getting Tax from Citizen\n";
  return 1;
  // return citizen->getTax();
}

double CitizenTaxAB::visit(Building* business) {
  std::cout << "Getting Tax from Bussiness\n";
  return 1;
	// return business->getTax();
}
