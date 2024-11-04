#include "FactResidential.h"

/**
 * @class FactResidential
 * @brief Factory class for creating residential building instances.
 * 
 * This class implements a factory pattern to create instances of 
 * various residential building types such as houses, townhouses, flats, and estates.
 */

/**
 * @brief Constructor for the FactResidential class.
 * 
 * Initializes a new instance of the FactResidential and outputs a creation message.
 */
FactResidential::FactResidential() {
    cout << BLACK << "\t->Residential factory created" << RESET << endl;
}

/**
 * @brief Creates a residential building based on the specified type.
 * 
 * @param type A string representing the type of residential building to create.
 * 
 * @return A pointer to the created Residential object, or nullptr if the type is not recognized.
 */
Residential* FactResidential::createResBuilding(string type) {
    if (type == "House") {
        return new ResHouse();
    } else if (type == "Townhouse") {
        return new ResTownhouse();
    } else if (type == "Flat") {
        return new ResFlat();
    } else if (type == "Estate") {
        return new ResEstate();
    }
    return nullptr;
}

/**
 * @brief Creates a commercial building based on the specified type.
 * 
 * This method is not implemented for residential factories.
 * 
 * @param type A string representing the type of commercial building to create.
 * 
 * @return Always returns nullptr.
 */
Commercial* FactResidential::createComBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates an industrial building based on the specified type.
 * 
 * This method is not implemented for residential factories.
 * 
 * @param type A string representing the type of industrial building to create.
 * 
 * @return Always returns nullptr.
 */
Industrial* FactResidential::createIndBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a landmark based on the specified type.
 * 
 * This method is not implemented for residential factories.
 * 
 * @param type A string representing the type of landmark to create.
 * 
 * @return Always returns nullptr.
 */
Landmark* FactResidential::createLandmark(string type) {
    return nullptr;
}

/**
 * @brief Creates a service building based on the specified type.
 * 
 * This method is not implemented for residential factories.
 * 
 * @param type A string representing the type of service building to create.
 * 
 * @return Always returns nullptr.
 */
Services* FactResidential::createServiceBuilding(string type) {
    return nullptr;
}
