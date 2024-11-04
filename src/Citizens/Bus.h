#ifndef BUS_H
#define BUS_H

#include <vector>
#include <utility>
#include <memory> // Include for smart pointers
#include "Citizen.h"

class RoadComponent;

/**
 * @class Bus
 * @brief Represents a bus that transports citizens between locations.
 *
 * The Bus class extends the Citizen class and manages a list of passengers,
 * their destinations, and the route taken by the bus.
 */
class Bus : public Citizen
{
private:
    /**
     * @brief A vector of pairs, where each pair contains a unique pointer to a Citizen
     *        and their corresponding destination RoadComponent.
     */
    std::vector<std::pair<std::unique_ptr<Citizen>, std::shared_ptr<RoadComponent>>> passengers;

    /** The maximum number of passengers the bus can carry. */
    int capacity;

    /** A vector representing the route of the bus. */
    std::vector<std::shared_ptr<RoadComponent>> route;

    /** The current location of the bus on the route. */
    std::shared_ptr<RoadComponent> currentLocation;

    /**
     * @brief Recalculates the route to the specified destination.
     * @param destination A shared pointer to the RoadComponent representing the new destination.
     */
    void recalculateRoute(std::shared_ptr<RoadComponent> destination);

public:
    /**
     * @brief Constructs a Bus with a starting location and capacity.
     * @param start A shared pointer to the initial RoadComponent where the bus starts.
     * @param capacity The maximum number of passengers the bus can hold.
     */
    Bus(std::shared_ptr<RoadComponent> start, int capacity);

    /**
     * @brief Checks if the bus is full.
     * @return True if the bus is at capacity; otherwise, false.
     */
    bool isFull();

    /**
     * @brief Adds a passenger to the bus and sets their destination.
     * @param passenger A unique pointer to the Citizen being added as a passenger.
     * @param destination A shared pointer to the RoadComponent representing the passenger's destination.
     */
    void addPassenger(std::unique_ptr<Citizen> passenger, std::shared_ptr<RoadComponent> destination);

    /**
     * @brief Removes a passenger from the bus.
     * @param passenger A pointer to the Citizen being removed from the bus.
     */
    void removePassenger(Citizen* passenger); // Change to take raw pointer for passenger removal

    /**
     * @brief Executes the bus's actions (e.g., moving, picking up passengers).
     */
    void doSomething();

    /**
     * @brief Notifies the bus of a change in state or status.
     * @param message A string containing information about the change.
     */
    void notifyChange(std::string message);

    /**
     * @brief Gets the current location of the bus.
     * @return A shared pointer to the RoadComponent where the bus is currently located.
     */
    std::shared_ptr<RoadComponent> getCurrentLocation() const; // Ensure this matches the implementation

    /**
     * @brief Destructor for the Bus class.
     */
    ~Bus();
};

#endif // BUS_H
