#include "TaxCollectionHandler.h"

void TaxCollectionHandler::handleRequest(TaxCommand* command) {
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
  else {
    command->execute();
  }
}
