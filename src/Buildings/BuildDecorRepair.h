#ifndef BUILDDECORREPAIR_H
#define BUILDDECORREPAIR_H

#include "BuildingDecorator.h"

/**
 * @class BuildDecorRepair
 * @brief Concrete decorator class that adds repair features to a Building.
 *
 * This class extends the BuildingDecorator class and can be used to
 * apply repair enhancements to a building, potentially affecting its 
 * condition and display information.
 */
class BuildDecorRepair : public BuildingDecorator {
public:
    /**
     * @brief Constructs a BuildDecorRepair object that decorates a building.
     * @param b Pointer to the Building object to be decorated.
     */
    BuildDecorRepair(Building* b);

    /**
     * @brief Displays information about the building with repair enhancements.
     * This method overrides the displayBuildingInfo method of the 
     * BuildingDecorator class to include additional repair details.
     */
    virtual void displayBuildingInfo() override;
};

#endif // BUILDDECORREPAIR_H
