#include "TaxAllocationHandler.h"
#include "TaxCommand.h"

void TaxAllocationHandler::handleRequest(TaxCommand* command) {
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
  else {
    command->execute();
  }
}
