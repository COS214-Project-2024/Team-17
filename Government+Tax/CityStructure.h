#ifndef CITYSTRUCTURE_H
#define CITYSTRUCTURE_H

class CityStructure {

private:
	vector<CityBlock*> blocks;

public:
	void accept(TaxAndBudgetVisitor* visitor);

	void addBlock(CityBlock* block);
};

#endif
