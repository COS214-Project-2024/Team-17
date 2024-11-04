#ifndef HIGHWAYS_H
#define HIGHWAYS_H

#include "../RoadComponent.h"

/**
 * @class Highways
 * @brief Represents a highway component in the road network.
 *
 * The Highways class is a derived class from RoadComponent and includes
 * methods to manage and interact with highway segments, including 
 * displaying information, calculating traffic, and managing connections.
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
     * @brief Displays information about the highway, such as its coordinates.
     */
    void displayInfo();

    /**
     * @brief Calculates the traffic on the highway based on certain parameters.
     */
    void calculateTraffic();

    /**
     * @brief Retrieves the distance of the highway segment.
     * @return The distance of the highway as a float.
     */
    float getDistance();

    /**
     * @brief Notifies about changes related to the highway.
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
     * @brief Calculates the distance from a specified point to the highway.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return The distance to the highway as a float.
     */
    float calculateDistance(int x, int y);

    /**
     * @brief Destructor for the Highways class.
     */
    ~Highways() {}
};

#endif // HIGHWAYS_H
