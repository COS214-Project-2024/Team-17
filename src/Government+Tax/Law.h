/**
 * @file Law.h
 * @brief Header file for the Law class, representing a legal policy that the government can enact.
 * @details This file defines the Law class, which inherits from the Policy class. It provides a base
 * interface for creating and enacting laws within a governmental system. Specific laws derived from this
 * class can implement additional functionality through the `enact()` method.
 * @see Policy for the base policy interface this class extends.
 * @see Government for the entity responsible for enforcing the enacted laws.
 * @note This class serves as a foundation for legal policies, allowing flexibility in defining new laws.
 * @author WORKONMYMACHINE TEAM
 */
#ifndef LAW_H
#define LAW_H

#include "Policy.h"
/**
 * @class Law
 * @brief Represents a legal policy that can be enacted by the government.
 */
class Law : public Policy
{
  public:
    /**
     * @brief Constructs a new Law instance with the specified government.
     * @param gov Pointer to the Government instance responsible for enforcing the law.
     */
    Law(Government* gov) : Policy(gov){};
      /**
     * @brief Enacts the law within the government.
     */
    virtual void enact() {};
};
#endif