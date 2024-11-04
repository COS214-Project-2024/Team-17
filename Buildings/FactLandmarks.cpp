#include "FactLandmarks.h"

/**
 * @class FactLandmarks
 * @brief Factory class for creating landmark instances.
 * 
 * This class implements a factory pattern to create instances of 
 * various landmark types such as parks, community centers, and monuments.
 */

/**
 * @brief Constructor for the FactLandmarks class.
 * 
 * Initializes a new instance of the FactLandmarks and outputs a creation message.
 */
FactLandmarks::FactLandmarks() {
    cout << BLACK << "\t->Landmark factory created" << RESET << endl;
}

/**
 * @brief Creates a landmark based on the specified type.
 * 
 * @param type A string representing the type of landmark to create.
 * 
 * @return A pointer to the created Landmark object, or nullptr if the type is not recognized.
 */
Landmark* FactLandmarks::createLandmark(string type) {
    if (type == "Park") {
        return new LandPark();
    } else if (type == "Community Center") {
        return new LandCCenter();
    } else if (type == "Monument") {
        return new LandMonument();
    }
    return nullptr;
}

/**
 * @brief Creates a residential building based on the specified type.
 * 
 * This method is not implemented for landmark factories.
 * 
 * @param type A string representing the type of residential building to create.
 * 
 * @return Always returns nullptr.
 */
Residential* FactLandmarks::createResBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a commercial building based on the specified type.
 * 
 * This method is not implemented for landmark factories.
 * 
 * @param type A string representing the type of commercial building to create.
 * 
 * @return Always returns nullptr.
 */
Commercial* FactLandmarks::createComBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates an industrial building based on the specified type.
 * 
 * This method is not implemented for landmark factories.
 * 
 * @param type A string representing the type of industrial building to create.
 * 
 * @return Always returns nullptr.
 */
Industrial* FactLandmarks::createIndBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a service building based on the specified type.
 * 
 * This method is not implemented for landmark factories.
 * 
 * @param type A string representing the type of service building to create.
 * 
 * @return Always returns nullptr.
 */
Services* FactLandmarks::createServiceBuilding(string type) {
    return nullptr;
}
