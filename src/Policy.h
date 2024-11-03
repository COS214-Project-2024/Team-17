#ifndef POLICY_H
#define POLICY_H

//bus lane law
//happiness law
//money law
//no tax law
//resources::tickincome * 1.2?
//services reduce citizen contention

struct Policy
{
  private:
    static bool busLaw;
    static bool happinessLaw;
    static bool moneyLaw;
    static bool noTaxLaw;
    static bool servicesLaw;
  public:
    static void setBusLaw(bool);
    static bool getBusLaw();
    
    static void setHappinessLaw(bool);
    static bool getHappinessLaw();

    static void setMoneyLaw(bool);
    static bool getMoneyLaw();

    static void setNoTaxLaw(bool);
    static bool getNoTaxLaw();

    static void setServicesLaw(bool);
    static bool getServicesLaw();
};
#endif