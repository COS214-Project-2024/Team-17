#ifndef RESIDENTIALSTREETS_H
#define RESIDENTIALSTREETS_H

#include "../RoadComponent.h"
#include <iostream>

/**
 * @class ResidentialStreets
 * @brief Represents a residential street component in the road network.
 *
 * The ResidentialStreets class is derived from the RoadComponent class and 
 * provides functionality for managing and interacting with residential 
 * street segments, including displaying information, calculating traffic, 
 * and managing connections to other road components.
 */
class ResidentialStreets : public RoadComponent
{

public:

    /**
     * @brief Constructs a ResidentialStreets object with specified start and end coordinates.
     * @param sX The starting X coordinate of the residential street.
     * @param sY The starting Y coordinate of the residential street.
     * @param eX The ending X coordinate of the residential street.
     * @param eY The ending Y coordinate of the residential street.
     */
	ResidentialStreets(int sX, int sY, int eX, int eY);
    /**
     * @brief Displays information about the residential street, such as its coordinates.
     */
	void displayInfo();
    /**
     * @brief Calculates the traffic on the residential street based on certain parameters.
     */
	void calculateTraffic();
    /**
     * @brief Retrieves the distance of the residential street segment.
     * @return The distance of the residential street as a float.
     */
	float getDistance();
    /**
     * @brief Notifies about changes related to the residential street.
     * @param message A string describing the nature of the change.
     */
	void notifyChange(std::string message);
    /**
     * @brief Adds a connection to another road component.
     * @param connection A pointer to the RoadComponent to connect to.
     * @param distance The distance to the connected road component.
     */
	void addConnection(RoadComponent *connection, float distance);
    /**
     * @brief Calculates the distance from a specified point to the residential street.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return The distance to the residential street as a float.
     */
	float calculateDistance(int x, int y);
    /**
     * @brief Destructor for the ResidentialStreets class.
     */
	~ResidentialStreets() {}
};

#endif