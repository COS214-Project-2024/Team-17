#ifndef FACTLANDMARKS_H
#define FACTLANDMARKS_H

#include "FactoryBuilding.h"
#include "LandPark.h"
#include "LandMonument.h"
#include "LandCCenter.h"

/**
 * @class FactLandmarks
 * @brief Factory class for creating landmark buildings.
 *
 * The FactLandmarks class is a concrete implementation of the FactoryBuilding
 * interface that provides methods to create various types of landmark buildings,
 * such as parks, monuments, and community centers.
 */
class FactLandmarks : public FactoryBuilding {
public:
    /**
     * @brief Default constructor for FactLandmarks.
     */
    FactLandmarks();

    /**
     * @brief Creates a landmark of a specified type.
     * @param type The type of landmark to create (e.g., "Park", "Monument", "Community Center").
     * @return A pointer to the created Landmark object.
     */
    Landmark* createLandmark(string type) override;

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
     * @brief Creates an industrial building (not implemented in this factory).
     * @param type The type of industrial building to create.
     * @return Always returns nullptr as this factory does not create industrial buildings.
     */
    Industrial* createIndBuilding(string type) override;

    /**
     * @brief Creates a service building (not implemented in this factory).
     * @param type The type of service building to create.
     * @return Always returns nullptr as this factory does not create service buildings.
     */
    Services* createServiceBuilding(string type) override;
};

#endif // FACTLANDMARKS_H
