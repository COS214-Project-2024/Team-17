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
    if (type == "Mall") {
        return nullptr;
    } else if (type == "Shop") {
        return nullptr;
    } else if (type == "Office") {
        return nullptr;
    }
    return nullptr;
}
Industrial* FactResidential::createIndBuilding(string type) {
    if (type == "Factory") {
        return nullptr;
    } else if (type == "Warehouse") {
        return nullptr;
    } else if (type == "Plant") {
        return nullptr;
    }
    return nullptr;
}
Landmark* FactResidential::createLandmark(string type) {
        if (type == "Park") {
        return nullptr;
    } else if (type == "Community Center") {
        return nullptr;
    } else if (type == "Monument") {
        return nullptr;
    }
    return nullptr;
}
Services* FactResidential::createServiceBuilding(string type) {
        if (type == "Education") {
        return nullptr;
    } else if (type == "Security") {
        return nullptr;
    } else if (type == "Entertainment") {
        return nullptr;
    }
    return nullptr;
}
