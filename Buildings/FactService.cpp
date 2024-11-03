#include "FactService.h"

FactService::FactService() {
    cout << BLACK << "\t->Service factory created" << RESET << endl;
}

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

Residential* FactService::createResBuilding(string type) {
    return nullptr;
}

Commercial* FactService::createComBuilding(string type) {
    return nullptr;
}
Industrial* FactService::createIndBuilding(string type) {
    return nullptr;
}
Landmark* FactService::createLandmark(string type) {
    return nullptr;
}