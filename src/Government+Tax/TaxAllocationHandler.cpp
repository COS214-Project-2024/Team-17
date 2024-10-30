#include "TaxAllocationHandler.h"
#include "TaxCommand.h"
#include <iostream>

void TaxAllocationHandler::handleRequest(TaxCommand *command)
{
  if (nextHandler)
  {
    std::cout << "Giving command to next handler\n";
    nextHandler->handleRequest(command);
  }
  else
  {
    std::cout << "executing command in this allocation handler\n";
    command->execute();
  }
}
