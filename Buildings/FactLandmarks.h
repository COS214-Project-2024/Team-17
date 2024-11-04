#ifndef FACTLANDMARKS_H
#define FACTLANDMARKS_H

#include "FactoryBuilding.h"
#include "LandPark.h"
#include "LandMonument.h"
#include "LandCCenter.h"

class FactLandmarks : public FactoryBuilding {
public:
    FactLandmarks();

    Landmark* createLandmark(string type) override;

    Residential* createResBuilding(string type) override;
    Commercial* createComBuilding(string type) override;
    Industrial* createIndBuilding(string type) override;
    Services* createServiceBuilding(string type) override;
};

#endif
