#ifndef BUILDDECORUPGRADE_H
#define BUILDDECORUPGRADE_H

#include "BuildingDecorator.h"
/**
 * @class BuildDecorUpgrade
 * @brief Concrete decorator class that adds upgrade features to a Building.
 *
 * This class extends the BuildingDecorator class and can be used to 
 * apply additional decorative upgrades to a building, enhancing its 
 * properties and possibly its display information.
 */
class BuildDecorUpgrade : public BuildingDecorator {
public:
    /**
     * @brief Constructs a BuildDecorUpgrade object that decorates a building.
     * @param b Pointer to the Building object to be decorated.
     */
    BuildDecorUpgrade(Building* b);
    /**
     * @brief Displays information about the building with upgrades.
     * This method overrides the displayBuildingInfo method of the 
     * BuildingDecorator class to include additional upgrade details.
     */
    virtual void displayBuildingInfo() override;
};

#endif
