#include "TaxAllocationHandler.h"

void TaxAllocationHandler::handleRequest(TaxCommand* command) {
  // do allocation
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
}
