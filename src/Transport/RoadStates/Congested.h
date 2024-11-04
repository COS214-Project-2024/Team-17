#ifndef CONGESTED_H
#define CONGESTED_H

#include "../RoadState.h"

/**
 * @class Congested
 * @brief Represents a congested state for a road component.
 *
 * The Congested class implements the RoadState interface, providing specific
 * behavior for handling traffic when a road is congested.
 */
class Congested : public RoadState
{
public:
    /**
     * @brief Handles traffic for the congested road.
     * 
     * This method implements the logic for managing traffic on a road
     * component that is currently in a congested state.
     * 
     * @param road Pointer to the RoadComponent that is congested.
     */
    virtual void handleTraffic(RoadComponent *road);

    /**
     * @brief Retrieves the status of the road state.
     * 
     * @return A string representing the current status of the road (e.g., "Congested").
     */
    virtual std::string getStatus();
};

#endif // CONGESTED_H
