#ifndef FACTSERVICE_H
#define FACTSERVICE_H

#include "FactoryBuilding.h"
#include "ServEducation.h"
#include "ServSecurity.h"
#include "ServEntertainment.h"


class FactService : public FactoryBuilding {
public:
    FactService();
    Services* createServiceBuilding(string type) override;

    Residential* createResBuilding(string type) override;
    Commercial* createComBuilding(string type) override;
    Industrial* createIndBuilding(string type) override;
    Landmark* createLandmark(string type) override;
};

#endif
