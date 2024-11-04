#ifndef MAINROADS_H
#define MAINROADS_H

#include "../RoadComponent.h"
/**
 * @class MainRoads
 * @brief Represents a main road component in the road network.
 *
 * The MainRoads class is derived from the RoadComponent class and 
 * provides functionality for managing and interacting with main road 
 * segments, including displaying information, calculating traffic, 
 * and managing connections to other road components.
 */
class MainRoads : public RoadComponent
{

public:
    /**
     * @brief Constructs a MainRoads object with specified start and end coordinates.
     * @param sX The starting X coordinate of the main road.
     * @param sY The starting Y coordinate of the main road.
     * @param eX The ending X coordinate of the main road.
     * @param eY The ending Y coordinate of the main road.
     */
	MainRoads(int sX, int sY, int eX, int eY);
    /**
     * @brief Displays information about the main road, such as its coordinates.
     */
	void displayInfo();
    /**
     * @brief Calculates the traffic on the main road based on certain parameters.
     */
	void calculateTraffic();
    /**
     * @brief Retrieves the distance of the main road segment.
     * @return The distance of the main road as a float.
     */
	float getDistance();
    /**
     * @brief Notifies about changes related to the main road.
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
     * @brief Calculates the distance from a specified point to the main road.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return The distance to the main road as a float.
     */
	float calculateDistance(int x, int y);
    /**
     * @brief Destructor for the MainRoads class.
     */
	~MainRoads() {}
};

#endif