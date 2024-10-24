#include "FactResidential.h"

FactResidential::FactResidential() {
    cout << BLACK << "\t->Residential factory created" << RESET << endl;
}

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

Commercial* FactResidential::createComBuilding(string type) {
    return nullptr;
}
Industrial* FactResidential::createIndBuilding(string type) {
    return nullptr;
}
Landmark* FactResidential::createLandmark(string type) {
    return nullptr;
}
Services* FactResidential::createServiceBuilding(string type) {
    return nullptr;
}
