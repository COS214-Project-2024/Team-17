#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "../RoadState.h"
#include <string>
/**
 * @class UnderConstruction
 * @brief Represents a road state indicating that the road is under construction.
 *
 * The UnderConstruction class implements the RoadState interface, providing specific
 * behavior for handling traffic when a road is currently under construction.
 */
class UnderConstruction : public RoadState
{
public:
    /**
     * @brief Handles traffic for the road that is under construction.
     * 
     * This method implements the logic for managing traffic on a road
     * component that is currently in an under construction state.
     * 
     * @param road Pointer to the RoadComponent that is under construction.
     */
    virtual void handleTraffic(RoadComponent *road);

    /**
     * @brief Retrieves the status of the road state.
     * 
     * @return A string representing the current status of the road (e.g., "Under Construction").
     */
    virtual std::string getStatus();
};

#endif // UNDERCONSTRUCTION_H
