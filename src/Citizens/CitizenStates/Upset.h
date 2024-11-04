#ifndef UPSET_H
#define UPSET_H

#include "../CitizenState.h"

/**
 * @class Upset
 * @brief Represents the upset state of a Citizen.
 *
 * This class is a concrete implementation of the CitizenState interface,
 * indicating that a citizen is in an upset emotional state. It manages
 * transitions to other states based on changes in the citizen's situation.
 */
class Upset : public CitizenState
{
public:
    /**
     * @brief Handles a change in the citizen's situation, potentially transitioning
     *        to a different state.
     * @param change An integer representing the change that affects the citizen's state.
     * @return A pointer to the new CitizenState that results from the change.
     */
    std::unique_ptr<CitizenState> handleChange(int change) override;

    /**
     * @brief Retrieves the name of the current state.
     * @return A string representing the name of the upset state.
     */
    std::string getState() override;

    /**
     * @brief Destructor for the Upset class.
     */
    ~Upset() {}
};

#endif // UPSET_H
