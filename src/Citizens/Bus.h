#ifndef BUS_H
#define BUS_H

#include <vector>
#include <utility>
#include "Citizen.h"

class RoadComponent;

class Bus : Citizen
{
private:
    std::vector<std::pair<Citizen *, RoadComponent *>> passengers;
    int capacity;
    std::vector<RoadComponent *> route;
    RoadComponent *currentLocation;
    void recalculateRoute(RoadComponent *destination);

public:
    Bus(RoadComponent *start, int capacity);
    bool isFull();
    void addPassenger(Citizen *passenger, RoadComponent *destination);
    void removePassenger(Citizen *passenger);
    void doSomething();
    void notifyChange(std::string message);
    RoadComponent *getCurrentLocation();
    ~Bus();
};

#endif