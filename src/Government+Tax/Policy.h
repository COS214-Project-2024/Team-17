#ifndef POLICY_H
#define POLICY_H

class Government;

class Policy{
  protected:
    Government* gov;
  public:
    Policy(Government* government) : gov(government) {}
    virtual void enact() = 0;
};
#endif