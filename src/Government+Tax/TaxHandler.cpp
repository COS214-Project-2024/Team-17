#include "TaxHandler.h"

TaxHandler::TaxHandler()
{
  this->nextHandler = nullptr;
}

void TaxHandler::setNext(TaxHandler *next)
{
  this->nextHandler = next;
}

void TaxHandler::handleRequest(TaxCommand *command)
{
  if (nextHandler)
  {
    nextHandler->handleRequest(command);
  }
}
