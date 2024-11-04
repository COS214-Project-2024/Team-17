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