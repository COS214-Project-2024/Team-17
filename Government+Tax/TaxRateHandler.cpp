#include "TaxRateHandler.h"

void TaxRateHandler::handleRequest(TaxCommand* command) {
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
  else {
    command->execute();
  }
}
