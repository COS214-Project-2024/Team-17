#ifndef BUILDDECORECONOMIC_H
#define BUILDDECORECONOMIC_H

#include "BuildingDecorator.h"

/**
 * @class BuildDecorEconomic
 * @brief Concrete decorator class that adds economic features to a Building.
 *
 * This class extends the BuildingDecorator class and can be used to
 * apply economic enhancements to a building, potentially affecting its 
 * financial aspects and display information.
 */
class BuildDecorEconomic : public BuildingDecorator {
public:
    /**
     * @brief Constructs a BuildDecorEconomic object that decorates a building.
     * @param b Pointer to the Building object to be decorated.
     */
    BuildDecorEconomic(Building* b);

    /**
     * @brief Displays information about the building with economic enhancements.
     * This method overrides the displayBuildingInfo method of the 
     * BuildingDecorator class to include additional economic details.
     */
    virtual void displayBuildingInfo() override;
};

#endif // BUILDDECORECONOMIC_H
