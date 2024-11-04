#ifndef WORKINGNOISSUES_H
#define WORKINGNOISSUES_H

#include "../RoadState.h"

/**
 * @class WorkingNoIssues
 * @brief Represents a road state indicating that the road is operational without any issues.
 *
 * The WorkingNoIssues class implements the RoadState interface, providing specific
 * behavior for handling traffic when a road is functioning normally.
 */
class WorkingNoIssues : public RoadState
{
public:
    /**
     * @brief Handles traffic for a road that is operational with no issues.
     * 
     * This method implements the logic for managing traffic on a road
     * component that is currently functioning without any problems.
     * 
     * @param road Pointer to the RoadComponent that is operational.
     */
    virtual void handleTraffic(RoadComponent *road);

    /**
     * @brief Retrieves the status of the road state.
     * 
     * @return A string representing the current status of the road (e.g., "Working No Issues").
     */
    virtual std::string getStatus();
};

#endif // WORKINGNOISSUES_H
