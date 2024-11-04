#ifndef FACTRESIDENTIAL_H
#define FACTRESIDENTIAL_H

#include "FactoryBuilding.h"
#include "ResHouse.h"
#include "ResTownhouse.h"
#include "ResFlat.h"
#include "ResEstate.h"

class FactResidential : public FactoryBuilding {
public:
    FactResidential();
    Residential* createResBuilding(string type) override;

    Commercial* createComBuilding(string type) override;
    Industrial* createIndBuilding(string type) override;
    Landmark* createLandmark(string type) override;
    Services* createServiceBuilding(string type) override;
};

#endif
