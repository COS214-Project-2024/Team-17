#ifndef LAW_H
#define LAW_H

#include "Policy.h"

class Law : public Policy
{
  public:
    Law(Government* gov) : Policy(gov){};
    virtual void enact() {};
};
#endif