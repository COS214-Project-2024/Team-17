#include "SetTaxRateCommand.h"

SetTaxRateCommand::SetTaxRateCommand(Government* gov, double rate, std::string cat) {
  this->government = gov;
  this->taxRate = rate;
  this->category = cat;
}

void SetTaxRateCommand::execute() {
	// TODO - implement SetTaxRateCommand ::execute
	throw "Not yet implemented";
}
