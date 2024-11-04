#ifndef SHAREDVARIABLES_H
#define SHAREDVARIABLES_H
#include "DraggableFrame.h"
#include "DraggableRoad.h"

struct SharedVariables{
    static QVector<DraggableFrame *> buildings;
    static QVector<DraggableRoad *> roads;
}

#endif // SHAREDVARIABLES_H
