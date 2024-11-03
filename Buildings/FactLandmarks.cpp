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
    return nullptr;
}
Commercial* FactLandmarks::createComBuilding(string type) {
    return nullptr;
}
Industrial* FactLandmarks::createIndBuilding(string type) {
    return nullptr;
}
Services* FactLandmarks::createServiceBuilding(string type) {
    return nullptr;
}

