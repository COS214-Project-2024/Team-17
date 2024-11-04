#ifndef ROADSCOMPOSITE_H
#define ROADSCOMPOSITE_H

#include "../RoadComponent.h"
#include <vector>

/**
 * @class RoadsComposite
 * @brief Represents a composite road component consisting of multiple road sections.
 *
 * The RoadsComposite class allows for the management of a collection of 
 * RoadComponent objects, enabling operations like adding, removing, 
 * and calculating traffic for a composite road section.
 */
class RoadsComposite : public RoadComponent
{
private:
    std::vector<RoadComponent *> components; ///< Collection of road components that make up the composite road.

public:
    static const int MAX_SECTION_DISTANCE = 100; ///< Maximum distance for road sections.

    /**
     * @brief Constructor for RoadsComposite.
     * @param sX The starting X coordinate of the composite road.
     * @param sY The starting Y coordinate of the composite road.
     * @param eX The ending X coordinate of the composite road.
     * @param eY The ending Y coordinate of the composite road.
     * @param type The type of road (e.g., highway, main road, residential).
     */
    RoadsComposite(int sX, int sY, int eX, int eY, std::string type);

    /**
     * @brief Displays information about the composite road and its sections.
     */
    void displayInfo();

    /**
     * @brief Calculates the traffic for the composite road based on its sections.
     */
    void calculateTraffic();

    /**
     * @brief Adds a road component to the composite road.
     * @param component A pointer to the RoadComponent to add.
     */
    void add(RoadComponent *component);

    /**
     * @brief Removes a road component from the composite road.
     * @param component A pointer to the RoadComponent to remove.
     */
    void remove(RoadComponent *component);

    /**
     * @brief Retrieves the total distance of the composite road.
     * @return The total distance as a float.
     */
    float getDistance();

    /**
     * @brief Notifies about changes related to the composite road.
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
     * @brief Retrieves all connections to other road components.
     * @return A vector of pointers to connected RoadComponent objects.
     */
    std::vector<RoadComponent *> getConnections();

    /**
     * @brief Retrieves a constant reference to the components of the composite road.
     * @return A constant vector of pointers to RoadComponent objects.
     */
    const std::vector<RoadComponent *> &getComponents() const;

    /**
     * @brief Calculates the distance from a specified point to the composite road.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return The distance to the composite road as a float.
     */
    float calculateDistance(int x, int y);

    /**
     * @brief Finds the closest road section to a specified point.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return A pointer to the closest RoadComponent.
     */
    RoadComponent *closestSection(int x, int y);

    /**
     * @brief Destructor for the RoadsComposite class.
     */
    ~RoadsComposite() {}
};

#endif // ROADSCOMPOSITE_H
