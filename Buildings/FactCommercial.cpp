#include "FactCommercial.h"

/**
 * @class FactCommercial
 * @brief Factory class for creating commercial building instances.
 * 
 * This class implements a factory pattern to create instances of 
 * various commercial building types such as malls, shops, and offices.
 */

/**
 * @brief Constructor for the FactCommercial class.
 * 
 * Initializes a new instance of the FactCommercial and outputs a creation message.
 */
FactCommercial::FactCommercial() {
    cout << BLACK << "\t->Commercial factory created" << RESET << endl;
}

/**
 * @brief Creates a commercial building based on the specified type.
 * 
 * @param type A string representing the type of commercial building to create.
 * 
 * @return A pointer to the created Commercial object, or nullptr if the type is not recognized.
 */
Commercial* FactCommercial::createComBuilding(string type) {
    if (type == "Mall") {
        return new ComMall();
    } else if (type == "Shop") {
        return new ComShop();
    } else if (type == "Office") {
        return new ComOffice();
    }
    return nullptr;
}

/**
 * @brief Creates a residential building based on the specified type.
 * 
 * This method is not implemented for commercial factories.
 * 
 * @param type A string representing the type of residential building to create.
 * 
 * @return Always returns nullptr.
 */
Residential* FactCommercial::createResBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates an industrial building based on the specified type.
 * 
 * This method is not implemented for commercial factories.
 * 
 * @param type A string representing the type of industrial building to create.
 * 
 * @return Always returns nullptr.
 */
Industrial* FactCommercial::createIndBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a landmark based on the specified type.
 * 
 * This method is not implemented for commercial factories.
 * 
 * @param type A string representing the type of landmark to create.
 * 
 * @return Always returns nullptr.
 */
Landmark* FactCommercial::createLandmark(string type) {
    return nullptr;
}

/**
 * @brief Creates a service building based on the specified type.
 * 
 * This method is not implemented for commercial factories.
 * 
 * @param type A string representing the type of service building to create.
 * 
 * @return Always returns nullptr.
 */
Services* FactCommercial::createServiceBuilding(string type) {
    return nullptr;
}
