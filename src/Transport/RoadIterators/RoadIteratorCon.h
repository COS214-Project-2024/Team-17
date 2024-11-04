#ifndef ROADITERATORCON_H
#define ROADITERATORCON_H

#include "../RoadIterator.h"
#include <vector>

/**
 * @class RoadIteratorCon
 * @brief Concrete iterator for traversing a collection of road components.
 *
 * The RoadIteratorCon class provides an implementation of the RoadIterator
 * interface, allowing for sequential access to the elements of a vector of
 * RoadComponent objects.
 */
class RoadIteratorCon : public RoadIterator
{
private:
    int current; ///< The current index in the vector of road components.
    std::vector<RoadComponent *> *roads; ///< Pointer to the vector containing road components.

public:
    /**
     * @brief Constructor for RoadIteratorCon.
     * @param roads A pointer to the vector of RoadComponent objects to iterate over.
     */
    RoadIteratorCon(std::vector<RoadComponent *> *roads);

    /**
     * @brief Resets the iterator to the first element of the collection.
     */
    virtual void first();

    /**
     * @brief Advances the iterator to the next element in the collection.
     */
    virtual void next();

    /**
     * @brief Checks if the iterator has reached the end of the collection.
     * @return True if the iterator is at the end; otherwise, false.
     */
    virtual bool isDone();

    /**
     * @brief Retrieves the current RoadComponent at the iterator's position.
     * @return A pointer to the current RoadComponent.
     */
    virtual RoadComponent *currentRoad();
};

#endif // ROADITERATORCON_H
