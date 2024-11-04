#ifndef BUILDDECORUPGRADE_H
#define BUILDDECORUPGRADE_H

#include "BuildingDecorator.h"

class BuildDecorUpgrade : public BuildingDecorator {
public:
    BuildDecorUpgrade(Building* b);
    virtual void displayBuildingInfo() override;
};

#endif
