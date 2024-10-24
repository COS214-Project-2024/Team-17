#ifndef FACTORYBUILDING_H
#define FACTORYBUILDING_H

#include "../colours.h" // Testing colours and other includes
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Services.h"

class FactoryBuilding {
public:
    virtual Residential* createResBuilding(string type) = 0;
    virtual Commercial* createComBuilding(string type) = 0;
    virtual Industrial* createIndBuilding(string type) = 0;
    virtual Landmark* createLandmark(string type) = 0;
    virtual Services* createServiceBuilding(string type) = 0;

    virtual ~FactoryBuilding(){}
};

#endif
