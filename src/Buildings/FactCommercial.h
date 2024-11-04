#ifndef FACTCOMMERCIAL_H
#define FACTCOMMERCIAL_H

#include "FactoryBuilding.h"
#include "ComMall.h"
#include "ComShop.h"
#include "ComOffice.h"

/**
 * @class FactCommercial
 * @brief Factory class for creating commercial buildings.
 *
 * The FactCommercial class is a concrete implementation of the FactoryBuilding
 * interface that provides methods to create various types of commercial buildings,
 * such as malls, shops, and offices.
 */
class FactCommercial : public FactoryBuilding {
public:
    /**
     * @brief Default constructor for FactCommercial.
     */
    FactCommercial();

    /**
     * @brief Creates a commercial building of a specified type.
     * @param type The type of commercial building to create (e.g., "Mall", "Shop", "Office").
     * @return A pointer to the created Commercial object.
     */
    Commercial* createComBuilding(string type) override;

    /**
     * @brief Creates a residential building (not implemented in this factory).
     * @param type The type of residential building to create.
     * @return Always returns nullptr as this factory does not create residential buildings.
     */
    Residential* createResBuilding(string type) override;

    /**
     * @brief Creates an industrial building (not implemented in this factory).
     * @param type The type of industrial building to create.
     * @return Always returns nullptr as this factory does not create industrial buildings.
     */
    Industrial* createIndBuilding(string type) override;

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

#endif // FACTCOMMERCIAL_H
