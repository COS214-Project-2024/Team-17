#include "TaxCollectionHandler.h"
#include "TaxCommand.h"
#include <iostream>

void TaxCollectionHandler::handleRequest(TaxCommand *command)
{
  if (nextHandler)
  {
    std::cout << "Giving command to next handler\n";
    nextHandler->handleRequest(command);
  }
  else
  {
    std::cout << "executing command in this collection handler\n";
    command->execute();
  }
}
