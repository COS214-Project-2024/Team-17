#include "TaxCollectionHandler.h"

void TaxCollectionHandler::handleRequest(TaxCommand* command) {
  // do Tax Collection
  if(nextHandler) {
    nextHandler->handleRequest(command);
  }
}
