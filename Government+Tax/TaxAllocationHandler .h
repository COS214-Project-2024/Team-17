#ifndef TAXALLOCATIONHANDLER _H
#define TAXALLOCATIONHANDLER _H

class TaxAllocationHandler_ : TaxHandler_ {


public:
	void handleRequest(TaxCommand* command);
};

#endif
