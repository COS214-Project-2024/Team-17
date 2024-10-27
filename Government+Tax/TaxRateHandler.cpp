#include "TaxRateHandler.h"
#include "TaxCommand.h"

void TaxRateHandler::handleRequest(TaxCommand* command) {
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
  else {
    command->execute();
  }
}
