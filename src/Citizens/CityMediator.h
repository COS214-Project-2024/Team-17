#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

#include <string>

class Building;
class UtilityManager;
class RoadState;
class Citizen;
class Bus;
class Trainstation;
class TaxAndBudgetVisitor;

/**
 * @class CityMediator
 * @brief Mediator class that facilitates communication between various city components.
 *
 * The CityMediator class acts as an intermediary, coordinating interactions 
 * between buildings, utilities, citizens, buses, and train stations.
 * It ensures that all components can communicate and respond to changes 
 * within the city ecosystem.
 */
class CityMediator
{
public:
    /**
     * @brief Registers a building with the city mediator.
     * @param building A pointer to the building to register.
     */
    virtual void registerBuilding(Building *building) = 0;

    /**
     * @brief Registers a utility manager with the city mediator.
     * @param util A pointer to the utility manager to register.
     */
    virtual void registerUtility(UtilityManager *util) = 0;

    /**
     * @brief Registers a citizen with the city mediator.
     * @param citizen A pointer to the citizen to register.
     */
    virtual void registerCitizen(Citizen *citizen) = 0;

    /**
     * @brief Registers a bus with the city mediator.
     * @param bus A pointer to the bus to register.
     */
    virtual void registerBus(Bus *bus) = 0;

    /**
     * @brief Registers a train station with the city mediator.
     * @param trainStation A pointer to the train station to register.
     */
    virtual void registerTrainStation(Trainstation *trainStation) = 0;

    /**
     * @brief Notifies the mediator of changes in a building.
     * @param building A pointer to the building that has changed.
     * @param message A string message detailing the change.
     */
    virtual void notifyBuildingChange(Building *building, std::string message) = 0;

    /**
     * @brief Notifies the mediator of changes in a utility.
     * @param type A pointer to the utility manager type that has changed.
     * @param status The new status of the utility.
     * @param message A string message detailing the change.
     */
    virtual void notifyUtilityChange(UtilityManager *type, bool status, std::string message) = 0;

    /**
     * @brief Notifies the mediator of changes in road state.
     * @param status A pointer to the road state that has changed.
     * @param message A string message detailing the change.
     */
    virtual void notifyRoadChange(RoadState *status, std::string message) = 0;

    /**
     * @brief Accepts a TaxAndBudgetVisitor to perform operations.
     * @param visitor A pointer to the visitor that will perform operations.
     * @return A double representing the result of the visitor's operation.
     */
    virtual double accept(TaxAndBudgetVisitor *visitor) = 0;

    /**
     * @brief Virtual destructor for cleanup in derived classes.
     */
    virtual ~CityMediator() {}
};

#endif // CITYMEDIATOR_H
