#ifndef FACTSERVICE_H
#define FACTSERVICE_H

#include "FactoryBuilding.h"
#include "ServEducation.h"
#include "ServSecurity.h"
#include "ServEntertainment.h"

/**
 * @class FactService
 * @brief Represents a factory that creates various service buildings.
 *
 * The FactService class inherits from the FactoryBuilding class and implements
 * methods for creating different types of service buildings such as educational,
 * security, and entertainment services, as well as residential, commercial,
 * industrial, and landmark buildings.
 */
class FactService : public FactoryBuilding {
public:
    /**
     * @brief Default constructor for the FactService class.
     */
    FactService();

    /**
     * @brief Creates a service building of a specified type.
     * @param type The type of service building to create.
     * @return A pointer to the created Services object.
     */
    Services* createServiceBuilding(string type) override;

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
};

#endif // FACTSERVICE_H
