#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

class TaxCommand 
{
public:
  virtual ~TaxCommand() {}
	virtual void execute() = 0;
};

#endif
