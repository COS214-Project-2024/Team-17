#include "TaxManager.h"
#include <iostream>

void TaxManager::setCommand(TaxCommand* cmd) {
	this->command = cmd;
}

void TaxManager::executeCommand() {
  if(this->command) {
    this->command->execute();
  }
  else {
    std::cout << "No command set\n";
  }
}
