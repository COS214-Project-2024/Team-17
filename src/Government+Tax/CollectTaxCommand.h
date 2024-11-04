/**
 * @file CollectTaxCommand.h
 * @brief Header file for the CollectTaxCommand class, which encapsulates the tax collection command.
 * @details This file defines the CollectTaxCommand class, used to trigger the collection of taxes by the Government.
 * It implements the Command design pattern, allowing the Government to collect taxes from all associated cities
 * in response to a specific command execution.
 * @note CollectTaxCommand is part of a set of commands available to the Government for various tax and budget actions.
 * @see Government for the class that executes this command.
 * @see Command for the base command interface this class implements (if Command is an existing base class/interface).
 * @see AllocateTaxCommand for a related command that handles tax allocation rather than collection.
 * @author WORKONMYMACHINE TEAM
 */
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
