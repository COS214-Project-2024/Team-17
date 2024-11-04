#ifndef COLLECTTAXCOMMAND_H
#define COLLECTTAXCOMMAND_H

#include "TaxCommand.h"
#include "Government.h"
/**
 * @class CollectTaxCommand
 * @brief Command for collecting taxes from a government entity.
 *
 * This class is responsible for executing a tax collection operation on a Government instance.
 */
class CollectTaxCommand : public TaxCommand
{

private:
	Government *government;

public:
    /**
     * @brief Constructs a CollectTaxCommand with the specified government.
     * @param gov Pointer to the Government instance.
     */
	CollectTaxCommand(Government *gov);
    /**
     * @brief Executes the tax collection command.
     */
	void execute();
};

#endif
