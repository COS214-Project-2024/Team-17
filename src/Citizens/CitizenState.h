#ifndef CITIZENSTATE_H
#define CITIZENSTATE_H

#include <string>

/**
 * @class CitizenState
 * @brief Abstract base class representing the state of a citizen.
 *
 * The CitizenState class serves as an interface for different states that a citizen can have.
 * Derived classes should implement specific state behaviors and transitions.
 */
class CitizenState
{
public:
    /**
     * @brief Handles a change in state based on an integer value.
     * @param change An integer representing the change to be handled.
     * @return A pointer to the resulting CitizenState after handling the change.
     */
    virtual CitizenState *handleChange(int change) = 0;

    /**
     * @brief Gets a string representation of the current state.
     * @return The name of the current state as a string.
     */
    virtual std::string getState() = 0;

    /**
     * @brief Virtual destructor for the CitizenState class.
     * Ensures proper cleanup of derived classes.
     */
    virtual ~CitizenState() {};
};

#endif // CITIZENSTATE_H
