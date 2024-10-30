#include "FactLandmarks.h"

FactLandmarks::FactLandmarks() {
    cout << BLACK << "\t->Landmark factory created" << RESET << endl;
}

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

Residential* FactLandmarks::createResBuilding(string type) {
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
Commercial* FactLandmarks::createComBuilding(string type) {
    if (type == "Mall") {
        return nullptr;
    } else if (type == "Shop") {
        return nullptr;
    } else if (type == "Office") {
        return nullptr;
    }
    return nullptr;
}
Industrial* FactLandmarks::createIndBuilding(string type) {
    if (type == "Factory") {
        return nullptr;
    } else if (type == "Warehouse") {
        return nullptr;
    } else if (type == "Plant") {
        return nullptr;
    }
    return nullptr;
}
Services* FactLandmarks::createServiceBuilding(string type) {
        if (type == "Education") {
        return nullptr;
    } else if (type == "Security") {
        return nullptr;
    } else if (type == "Entertainment") {
        return nullptr;
    }
    return nullptr;
}

