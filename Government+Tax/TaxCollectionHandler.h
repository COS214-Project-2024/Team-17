#ifndef TAXCOLLECTIONHANDLER_H
#define TAXCOLLECTIONHANDLER_H

#include "TaxHandler.h"

class TaxCollectionHandler : public TaxHandler {
public:
	void handleRequest(TaxCommand* command);
};

#endif
