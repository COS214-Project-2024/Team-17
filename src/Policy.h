#ifndef POLICY_H
#define POLICY_H

//bus lane law
//happiness law
//money law
//no tax law
//resources::tickincome * 1.2?
//services reduce citizen contention
/**
 * @struct Policy
 * @brief Holds the various laws and policies affecting the simulation.
 *
 * This struct manages laws that influence the city's operations, 
 * including laws related to transport, happiness, finance, and services.
 */
struct Policy
{
  private:
    static bool busLaw;
    static bool happinessLaw;
    static bool moneyLaw;
    static bool noTaxLaw;
    static bool servicesLaw;
  public:
    /**
     * @brief Sets the status of the bus lane law.
     * @param status New status for the bus lane law.
     */
    static void setBusLaw(bool);
    /**
     * @brief Gets the status of the bus lane law.
     * @return Current status of the bus lane law.
     */
    static bool getBusLaw();
    /**
     * @brief Sets the status of the happiness law.
     * @param status New status for the happiness law.
     */
    static void setHappinessLaw(bool);
    /**
     * @brief Gets the status of the happiness law.
     * @return Current status of the happiness law.
     */
    static bool getHappinessLaw();
    /**
     * @brief Sets the status of the money law.
     * @param status New status for the money law.
     */
    static void setMoneyLaw(bool);
    /**
     * @brief Gets the status of the money law.
     * @return Current status of the money law.
     */
    static bool getMoneyLaw();
    /**
     * @brief Sets the status of the no tax law.
     * @param status New status for the no tax law.
     */
    static void setNoTaxLaw(bool);
    /**
     * @brief Gets the status of the no tax law.
     * @return Current status of the no tax law.
     */
    static bool getNoTaxLaw();
    /**
     * @brief Sets the status of the services law.
     * @param status New status for the services law.
     */
    static void setServicesLaw(bool);
    /**
     * @brief Gets the status of the services law.
     * @return Current status of the services law.
     */
    static bool getServicesLaw();
};
#endif