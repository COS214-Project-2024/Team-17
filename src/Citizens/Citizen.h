#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenStates/CitizenStatesIncludes.h"
#include "CityBlock.h"
#include "CityMediator.h"
#include <string>
#include <vector>
#include <memory>

class Bus;
class RoadComponent;
/**
 * @class Citizen
 * @brief Represents a citizen in the city simulation.
 *
 * The Citizen class extends CityBlock and encapsulates the properties and
 * behaviors of a citizen, including their state, location, workplace,
 * and activities.
 */
class Citizen : public CityBlock // Note the addition of 'public' here
{
protected:
    std::unique_ptr<CitizenState> state; // Use unique_ptr for state
    std::string name;
    std::shared_ptr<Building> workplace; // Use shared_ptr for shared ownership
    std::shared_ptr<Building> home;
    std::shared_ptr<Building> currentLocation;
    std::shared_ptr<RoadComponent> currentRoad;
    std::vector<std::shared_ptr<RoadComponent>> route; // Use shared_ptr for routes
    std::shared_ptr<CityMediator> mediator; // Use shared_ptr for mediator
    std::shared_ptr<Bus> myBus; // Use shared_ptr for Bus
    bool ownsCar;
    bool scheduledForDeletion = false;
    int waitTimer = 0;
    enum Activity
    {
        Rest,
        Work,
        TryBusWork,
        InTransitWork,
        AwaitTransitWork,
        TryBusHome,
        InTransitHome,
        AwaitTransitHome,
        Nothing
    };

    Activity activity;

    /**
     * @brief Changes the happiness level of the citizen.
     * @param change The amount to change happiness by (positive or negative).
     */
    void changeHappiness(int change);

public:
    /**
     * @brief Constructs a Citizen and optionally registers them automatically.
     * @param autoRegister Indicates whether the citizen should be auto-registered.
     */
    Citizen(bool autoRegister = true);

    /**
     * @brief Sets the state of the citizen.
     * @param newState A pointer to the new CitizenState to be assigned.
     */
    void setState(std::unique_ptr<CitizenState> newState); // Change to unique_ptr

    /**
     * @brief Gets the current state of the citizen.
     * @return A pointer to the current CitizenState.
     */
    CitizenState *getState();

    /**
     * @brief Notifies the citizen of a change in the environment or situation.
     * @param message A string containing information about the change.
     */
    void notifyChange(const std::string& message); // Use const reference

    /**
     * @brief Accepts a visitor for tax and budget operations.
     * @param visitor A pointer to the TaxAndBudgetVisitor.
     */
    void accept(TaxAndBudgetVisitor *visitor);

    /**
     * @brief Gets the name of the citizen.
     * @return The name of the citizen as a string.
     */
    std::string getName();

    /**
     * @brief Sets the citizen's workplace.
     * @param workplace A pointer to the Building representing the workplace.
     */
    void setWorkplace(std::shared_ptr<Building> workplace);

    /**
     * @brief Gets the citizen's workplace.
     * @return A pointer to the Building representing the workplace.
     */
    std::shared_ptr<Building> getWorkplace();

    /**
     * @brief Handles the event of the citizen being fired from their job.
     */
    void fired();

    /**
     * @brief Sets the citizen's home.
     * @param home A pointer to the Building representing the home.
     */
    void setHome(std::shared_ptr<Building> home);

    /**
     * @brief Gets the citizen's home.
     * @return A pointer to the Building representing the home.
     */
    std::shared_ptr<Building> getHome();

    /**
     * @brief Handles the event of the citizen being evicted.
     */
    void evicted();

    /**
     * @brief Gives a car to the citizen.
     */
    void giveCar();

    /**
     * @brief Performs the citizen's actions for the current iteration.
     */
    virtual void doSomething();

    /**
     * @brief Gets the current building where the citizen is located.
     * @return A pointer to the Building where the citizen currently is.
     */
    std::shared_ptr<Building> getCurrentBuilding();

    /**
     * @brief Gets the happiness level of the citizen.
     * @return The happiness level as an integer.
     */
    int getHappiness();

    /**
     * @brief Gets the tax obligations of the citizen.
     * @return The tax amount as a double.
     */
    double getTax();

    /**
     * @brief Destructor for the Citizen class.
     */
    ~Citizen();
};

#endif // CITIZEN_H
