#ifndef FACTINDUSTRIAL_H
#define FACTINDUSTRIAL_H

#include "FactoryBuilding.h"
#include "IndFactory.h"
#include "IndWarehouse.h"
#include "IndPlant.h"

class FactIndustrial : public FactoryBuilding {
public:
    FactIndustrial();
    Industrial* createIndBuilding(string type) override;

    Residential* createResBuilding(string type) override;
    Commercial* createComBuilding(string type) override;
    Landmark* createLandmark(string type) override;
    Services* createServiceBuilding(string type) override;
};

#endif


