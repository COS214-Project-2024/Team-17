#include "TaxManager.h"

void TaxManager::setCommand(TaxCommand* cmd) {
	this->command = cmd;
}

void TaxManager::executeCommand() {
  if(this->command) {
    this->command->execute();
  }
  else {
    throw "No command set";
  }
}
