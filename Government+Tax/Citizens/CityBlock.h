#ifndef CITYBLOCK_H
#define CITYBLOCK_H

class CityBlock {

protected:
	CityMediator* mediator;

public:
	CityBlock(CityMediator* mediator);

	virtual void abstract_notifyChange() = 0;

	virtual void accept(TaxAndBudgetVisitor* visitor) = 0;
};

#endif
