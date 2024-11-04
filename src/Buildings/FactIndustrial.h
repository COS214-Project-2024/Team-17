#ifndef FACTINDUSTRIAL_H
#define FACTINDUSTRIAL_H

#include "FactoryBuilding.h"
#include "IndFactory.h"
#include "IndWarehouse.h"
#include "IndPlant.h"

/**
 * @class FactIndustrial
 * @brief Factory class for creating industrial buildings.
 *
 * The FactIndustrial class is a concrete implementation of the FactoryBuilding
 * interface that provides methods to create various types of industrial buildings,
 * such as factories, warehouses, and plants.
 */
class FactIndustrial : public FactoryBuilding {
public:
    /**
     * @brief Default constructor for FactIndustrial.
     */
    FactIndustrial();

    /**
     * @brief Creates an industrial building of a specified type.
     * @param type The type of industrial building to create (e.g., "Factory", "Warehouse", "Plant").
     * @return A pointer to the created Industrial object.
     */
    Industrial* createIndBuilding(string type) override;

    /**
     * @brief Creates a residential building (not implemented in this factory).
     * @param type The type of residential building to create.
     * @return Always returns nullptr as this factory does not create residential buildings.
     */
    Residential* createResBuilding(string type) override;

    /**
     * @brief Creates a commercial building (not implemented in this factory).
     * @param type The type of commercial building to create.
     * @return Always returns nullptr as this factory does not create commercial buildings.
     */
    Commercial* createComBuilding(string type) override;

    /**
     * @brief Creates a landmark building (not implemented in this factory).
     * @param type The type of landmark building to create.
     * @return Always returns nullptr as this factory does not create landmark buildings.
     */
    Landmark* createLandmark(string type) override;

    /**
     * @brief Creates a service building (not implemented in this factory).
     * @param type The type of service building to create.
     * @return Always returns nullptr as this factory does not create service buildings.
     */
    Services* createServiceBuilding(string type) override;
};

#endif // FACTINDUSTRIAL_H
