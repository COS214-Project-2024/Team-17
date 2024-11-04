/**
 * @file AllocateTaxCommand.h
 * @brief Header file for the AllocateTaxCommand class, which allocates tax funds to a specified department.
 * @details This file defines the AllocateTaxCommand class, inheriting from TaxCommand, to allocate a specified
 * amount of tax funds to a department within the government structure. The command encapsulates the logic
 * for tax allocation, enhancing modularity in the Government's fiscal operations.
 * @see TaxCommand for the base command interface this class inherits.
 * @see Government for the entity that executes this command to manage departmental funds.
 * @see CityStructure for the city-level structure that receives the tax allocation.
 * @author WORKONMYMACHINE TEAM
 */
#ifndef ALLOCATETAXCOMMAND_H
#define ALLOCATETAXCOMMAND_H

#include "TaxCommand.h"
#include "Government.h"

#include <string>
/**
 * @class AllocateTaxCommand
 * @brief A command to allocate a specific amount of tax to a government department.
 *
 * This class inherits from TaxCommand and is responsible for executing an allocation
 * of tax funds to a specified department within a government entity.
 */
class AllocateTaxCommand : public TaxCommand
{

private:
    /**
     * @brief Pointer to the Government instance.
     *
     * This Government instance represents the entity to which tax funds will be allocated.
     */
	Government *government;
	    /**
     * @brief The amount of tax to be allocated.
     *
     * This value represents the amount of funds to be allocated to the specified department.
     */
	double amount;
	    /**
     * @brief The department receiving the tax allocation.
     *
     * This string specifies the department within the government that will receive the allocated funds.
     */
	std::string department;

public:
    /**
     * @brief Constructor for AllocateTaxCommand.
     *
     * Initializes a new instance of the AllocateTaxCommand with a target government, allocation amount, and department.
     *
     * @param gov Pointer to the Government instance where the tax is allocated.
     * @param amt The amount of tax funds to allocate.
     * @param dept The name of the department receiving the funds.
     */
	AllocateTaxCommand(Government *gov, double amt, std::string dept);
	    /**
     * @brief Executes the tax allocation command.
     *
     * Allocates the specified amount of tax funds to the designated department within the government.
     */
	void execute();
};

#endif
