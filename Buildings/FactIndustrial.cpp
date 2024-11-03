#include "FactIndustrial.h"

FactIndustrial::FactIndustrial() {
    cout << BLACK << "\t->Industrial factory created" << RESET << endl;
}

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

Residential* FactIndustrial::createResBuilding(string type) {
    return nullptr;
}
Commercial* FactIndustrial::createComBuilding(string type) {
    return nullptr;
}
Landmark* FactIndustrial::createLandmark(string type) {
    return nullptr;
}
Services* FactIndustrial::createServiceBuilding(string type) {
    return nullptr;
}