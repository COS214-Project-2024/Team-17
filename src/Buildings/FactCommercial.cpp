#include "FactCommercial.h"
/**
 * @class FactCommercial
 * @brief Factory class for creating various commercial buildings.
 *
 * This class implements a factory pattern to create instances of different types of commercial buildings,
 * such as malls, shops, and offices. It also provides empty implementations for residential,
 * industrial, landmark, and service buildings.
 */
FactCommercial::FactCommercial() {
    cout << BLACK << "\t->Commercial factory created" << RESET << endl;
}

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

Residential* FactCommercial::createResBuilding(string type) {
        if (type == "House") {
        return nullptr;
    } else if (type == "Townhouse") {
        return nullptr;
    } else if (type == "Flat") {
        return nullptr;
    } else if (type == "Estate") {
        return nullptr;
    }
    return nullptr;
}
Industrial* FactCommercial::createIndBuilding(string type) {
    if (type == "Factory") {
        return nullptr;
    } else if (type == "Warehouse") {
        return nullptr;
    } else if (type == "Plant") {
        return nullptr;
    }
    return nullptr;
}
Landmark* FactCommercial::createLandmark(string type) {
        if (type == "Park") {
        return nullptr;
    } else if (type == "Community Center") {
        return nullptr;
    } else if (type == "Monument") {
        return nullptr;
    }
    return nullptr;
}
Services* FactCommercial::createServiceBuilding(string type) {
        if (type == "Education") {
        return nullptr;
    } else if (type == "Security") {
        return nullptr;
    } else if (type == "Entertainment") {
        return nullptr;
    }
    return nullptr;
}