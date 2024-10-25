#include "TaxRateHandler.h"

void TaxRateHandler::handleRequest(TaxCommand* command) {
  // do TaxRate
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
}
