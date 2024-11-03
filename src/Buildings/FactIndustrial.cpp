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
    if (type == "House") {
        return nullptr;
    } else if (type == "Townhouse") {
        return nullptr;
    } else if (type == "Apartment") {
        return nullptr;
    }
    return nullptr;
}
Commercial* FactIndustrial::createComBuilding(string type) {
    if (type == "Mall") {
        return nullptr;
    } else if (type == "Shop") {
        return nullptr;
    } else if (type == "Office") {
        return nullptr;
    }
    return nullptr;
}
Landmark* FactIndustrial::createLandmark(string type) {
        if (type == "Park") {
        return nullptr;
    } else if (type == "Community Center") {
        return nullptr;
    } else if (type == "Monument") {
        return nullptr;
    }
    return nullptr;
}
Services* FactIndustrial::createServiceBuilding(string type) {
        if (type == "Education") {
        return nullptr;
    } else if (type == "Security") {
        return nullptr;
    } else if (type == "Entertainment") {
        return nullptr;
    }
    return nullptr;
}