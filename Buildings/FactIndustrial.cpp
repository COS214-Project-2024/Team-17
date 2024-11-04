#include "FactIndustrial.h"

/**
 * @class FactIndustrial
 * @brief Factory class for creating industrial building instances.
 * 
 * This class implements a factory pattern to create instances of 
 * various industrial building types such as factories, warehouses, and plants.
 */

/**
 * @brief Constructor for the FactIndustrial class.
 * 
 * Initializes a new instance of the FactIndustrial and outputs a creation message.
 */
FactIndustrial::FactIndustrial() {
    cout << BLACK << "\t->Industrial factory created" << RESET << endl;
}

/**
 * @brief Creates an industrial building based on the specified type.
 * 
 * @param type A string representing the type of industrial building to create.
 * 
 * @return A pointer to the created Industrial object, or nullptr if the type is not recognized.
 */
Industrial* FactIndustrial::createIndBuilding(string type) {
    if (type == "Factory") {
        return new IndFactory();
    } else if (type == "Warehouse") {
        return new IndWarehouse();
    } else if (type == "Plant") {
        return new IndPlant();
    }
    return nullptr;
}

/**
 * @brief Creates a residential building based on the specified type.
 * 
 * This method is not implemented for industrial factories.
 * 
 * @param type A string representing the type of residential building to create.
 * 
 * @return Always returns nullptr.
 */
Residential* FactIndustrial::createResBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a commercial building based on the specified type.
 * 
 * This method is not implemented for industrial factories.
 * 
 * @param type A string representing the type of commercial building to create.
 * 
 * @return Always returns nullptr.
 */
Commercial* FactIndustrial::createComBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a landmark based on the specified type.
 * 
 * This method is not implemented for industrial factories.
 * 
 * @param type A string representing the type of landmark to create.
 * 
 * @return Always returns nullptr.
 */
Landmark* FactIndustrial::createLandmark(string type) {
    return nullptr;
}

/**
 * @brief Creates a service building based on the specified type.
 * 
 * This method is not implemented for industrial factories.
 * 
 * @param type A string representing the type of service building to create.
 * 
 * @return Always returns nullptr.
 */
Services* FactIndustrial::createServiceBuilding(string type) {
    return nullptr;
}
