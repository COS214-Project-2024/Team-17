#ifndef TAXCOLLECTIONHANDLER _H
#define TAXCOLLECTIONHANDLER _H

class TaxCollectionHandler_ : TaxHandler_ {


public:
	void handleRequest(TaxCommand* command);
};

#endif
