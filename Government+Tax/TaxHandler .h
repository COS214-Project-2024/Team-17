#ifndef TAXHANDLER _H
#define TAXHANDLER _H

class TaxHandler_ {

protected:
	TaxHandler* nextHandler;

public:
	void TaxHandler();

	void setNext(TaxHandler* next);

	virtual void handleRequest(TaxCommand* command) = 0;
};

#endif
