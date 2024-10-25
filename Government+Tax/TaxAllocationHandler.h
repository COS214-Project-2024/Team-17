#ifndef TAXALLOCATIONHANDLER_H
#define TAXALLOCATIONHANDLER_H

#include "TaxHandler.h"

class TaxAllocationHandler : public TaxHandler {
public:
	void handleRequest(TaxCommand* command);
};

#endif
