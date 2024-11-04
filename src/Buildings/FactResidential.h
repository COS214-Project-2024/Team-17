#ifndef FACTRESIDENTIAL_H
#define FACTRESIDENTIAL_H

#include "FactoryBuilding.h"
#include "ResHouse.h"
#include "ResTownhouse.h"
#include "ResFlat.h"
#include "ResEstate.h"

/**
 * @class FactResidential
 * @brief Factory for creating residential buildings.
 *
 * The FactResidential class inherits from the FactoryBuilding class and
 * provides methods to create various types of residential buildings
 * such as houses, townhouses, flats, and estates.
 */
class FactResidential : public FactoryBuilding {
public:
    /**
     * @brief Default constructor for the FactResidential class.
     */
    FactResidential();

    /**
     * @brief Creates a residential building of a specified type.
     * @param type The type of residential building to create.
     * @return A pointer to the created Residential object.
     */
    Residential* createResBuilding(string type) override;

    /**
     * @brief Creates a commercial building of a specified type.
     * @param type The type of commercial building to create.
     * @return A pointer to the created Commercial object.
     */
    Commercial* createComBuilding(string type) override;

    /**
     * @brief Creates an industrial building of a specified type.
     * @param type The type of industrial building to create.
     * @return A pointer to the created Industrial object.
     */
    Industrial* createIndBuilding(string type) override;

    /**
     * @brief Creates a landmark of a specified type.
     * @param type The type of landmark to create.
     * @return A pointer to the created Landmark object.
     */
    Landmark* createLandmark(string type) override;

    /**
     * @brief Creates a service building of a specified type.
     * @param type The type of service building to create.
     * @return A pointer to the created Services object.
     */
    Services* createServiceBuilding(string type) override;
};

#endif // FACTRESIDENTIAL_H
