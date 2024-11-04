#ifndef HIGHWAYS_H
#define HIGHWAYS_H

#include "../RoadComponent.h"
/**
 * @class Highways
 * @brief Represents a highway component in the road network.
 *
 * The Highways class inherits from RoadComponent and provides functionalities
 * specific to highway segments, including traffic calculation, distance management,
 * and information display.
 */
class Highways : public RoadComponent
{

public:
    /**
     * @brief Constructs a Highways object with specified start and end coordinates.
     * @param sX The starting X coordinate of the highway.
     * @param sY The starting Y coordinate of the highway.
     * @param eX The ending X coordinate of the highway.
     * @param eY The ending Y coordinate of the highway.
     */
	Highways(int sX, int sY, int eX, int eY);
    /**
     * @brief Displays information about the highway.
     */
	void displayInfo();
    /**
     * @brief Calculates the traffic on the highway.
     */
	void calculateTraffic();
    /**
     * @brief Gets the distance of the highway segment.
     * @return The distance as a float.
     */
	float getDistance();
    /**
     * @brief Notifies of changes related to the highway.
     * @param message A string message detailing the change.
     */
	void notifyChange(std::string message);
    /**
     * @brief Adds a connection to another road component.
     * @param connection A pointer to the road component to connect.
     * @param distance The distance to the connected component.
     */
	void addConnection(RoadComponent *connection, float distance);
    /**
     * @brief Calculates the distance from a given point to the highway.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return The calculated distance as a float.
     */
	float calculateDistance(int x, int y);

	
    /**
     * @brief Destructor for cleanup.
     */
	~Highways() {}
};

#endif
