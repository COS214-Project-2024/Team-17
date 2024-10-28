#include "TaxRateHandler.h"
#include "TaxCommand.h"
#include <iostream>

void TaxRateHandler::handleRequest(TaxCommand* command) {
  if(nextHandler) {
    std::cout << "Giving command to next handler\n";
    nextHandler->handleRequest(command);
  }
  else {
    std::cout << "executing command in this tax rate handler\n";
    command->execute();
  }
}
