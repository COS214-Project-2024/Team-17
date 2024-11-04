#include "FactService.h"

/**
 * @class FactService
 * @brief Factory class for creating service building instances.
 * 
 * This class implements a factory pattern to create instances of 
 * various service building types such as education, security, and entertainment services.
 */

/**
 * @brief Constructor for the FactService class.
 * 
 * Initializes a new instance of the FactService and outputs a creation message.
 */
FactService::FactService() {
    cout << BLACK << "\t->Service factory created" << RESET << endl;
}

/**
 * @brief Creates a service building based on the specified type.
 * 
 * @param type A string representing the type of service building to create.
 * 
 * @return A pointer to the created Services object, or nullptr if the type is not recognized.
 */
Services* FactService::createServiceBuilding(string type) {
    if (type == "Education") {
        return new ServEducation();
    } else if (type == "Security") {
        return new ServSecurity();
    } else if (type == "Entertainment") {
        return new ServEntertainment();
    }
    return nullptr;
}

/**
 * @brief Creates a residential building based on the specified type.
 * 
 * This method is not implemented for service factories.
 * 
 * @param type A string representing the type of residential building to create.
 * 
 * @return Always returns nullptr.
 */
Residential* FactService::createResBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a commercial building based on the specified type.
 * 
 * This method is not implemented for service factories.
 * 
 * @param type A string representing the type of commercial building to create.
 * 
 * @return Always returns nullptr.
 */
Commercial* FactService::createComBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates an industrial building based on the specified type.
 * 
 * This method is not implemented for service factories.
 * 
 * @param type A string representing the type of industrial building to create.
 * 
 * @return Always returns nullptr.
 */
Industrial* FactService::createIndBuilding(string type) {
    return nullptr;
}

/**
 * @brief Creates a landmark based on the specified type.
 * 
 * This method is not implemented for service factories.
 * 
 * @param type A string representing the type of landmark to create.
 * 
 * @return Always returns nullptr.
 */
Landmark* FactService::createLandmark(string type) {
    return nullptr;
}
