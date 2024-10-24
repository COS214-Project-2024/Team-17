#include "FactCommercial.h"

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
    return nullptr;
}
Industrial* FactCommercial::createIndBuilding(string type) {
    return nullptr;
}
Landmark* FactCommercial::createLandmark(string type) {
    return nullptr;
}
Services* FactCommercial::createServiceBuilding(string type) {
    return nullptr;
}