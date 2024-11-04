#ifndef FACTORYBUILDING_H
#define FACTORYBUILDING_H

#include "../../colours.h" // Testing colours and other includes
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Services.h"

/**
 * @class FactoryBuilding
 * @brief Abstract base class for building factories.
 *
 * The FactoryBuilding class serves as an interface for creating various types
 * of buildings, including residential, commercial, industrial, landmarks, and
 * service buildings. Derived classes must implement the specified methods to
 * provide concrete building creation functionality.
 */
class FactoryBuilding
{
public:
    /**
     * @brief Creates a residential building of a specified type.
     * @param type The type of residential building to create.
     * @return A pointer to the created Residential object.
     */
    virtual Residential *createResBuilding(string type) = 0;

    /**
     * @brief Creates a commercial building of a specified type.
     * @param type The type of commercial building to create.
     * @return A pointer to the created Commercial object.
     */
    virtual Commercial *createComBuilding(string type) = 0;

    /**
     * @brief Creates an industrial building of a specified type.
     * @param type The type of industrial building to create.
     * @return A pointer to the created Industrial object.
     */
    virtual Industrial *createIndBuilding(string type) = 0;

    /**
     * @brief Creates a landmark of a specified type.
     * @param type The type of landmark to create.
     * @return A pointer to the created Landmark object.
     */
    virtual Landmark *createLandmark(string type) = 0;

    /**
     * @brief Creates a service building of a specified type.
     * @param type The type of service building to create.
     * @return A pointer to the created Services object.
     */
    virtual Services *createServiceBuilding(string type) = 0;

    /**
     * @brief Virtual destructor for FactoryBuilding.
     */
    virtual ~FactoryBuilding() {}
};

#endif // FACTORYBUILDING_H
