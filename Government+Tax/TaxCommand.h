#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include "Government.h"

class Government;

class TaxCommand 
{
public:
  virtual ~TaxCommand() {}
	virtual void execute() = 0;
};

#endif
