#ifndef FACTCOMMERCIAL_H
#define FACTCOMMERCIAL_H

#include "FactoryBuilding.h"
#include "ComMall.h"
#include "ComShop.h"
#include "ComOffice.h"

class FactCommercial : public FactoryBuilding {
public:
    FactCommercial();
    Commercial* createComBuilding(string type) override;

    Residential* createResBuilding(string type) override;
    Industrial* createIndBuilding(string type) override;
    Landmark* createLandmark(string type) override;
    Services* createServiceBuilding(string type) override;
};

#endif