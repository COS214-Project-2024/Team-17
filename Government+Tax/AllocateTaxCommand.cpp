#include "AllocateTaxCommand.h"

AllocateTaxCommand::AllocateTaxCommand(Government* gov, double amt, std::string dept) {
  this->government = gov;
  this->amount = amt;
  this->department = dept;
}

void AllocateTaxCommand::execute() {
	// TODO - implement AllocateTaxCommand ::execute
	throw "Not yet implemented";
}
