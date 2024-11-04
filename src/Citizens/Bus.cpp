#include "Bus.h"
#include "CityCentralMediator.h"
#include "../Transport/TransportInclude.h"
#include <iostream>
#include "../Policy.h"

static int busCount = 0;

void Bus::recalculateRoute(std::shared_ptr<RoadComponent> destination)
{
    CityCentralMediator *ccm = dynamic_cast<CityCentralMediator *>(this->mediator);

    if (destination == nullptr)
    {
        // Recalculate all routes
        for (auto& it : passengers)
        {
            // get last road component
            auto last = route.back();
            // calculate route from last to destination
            std::vector<std::shared_ptr<RoadComponent>> newRoute = ccm->calculateRoute(last, it.second);
            route.insert(route.end(), newRoute.begin(), newRoute.end());
        }
    }
    else
    {
        std::cout << "We have a destination" << std::endl;
        // Add single destination to route
        // Check if destination is on the way
        bool found = false;
        for (const auto& it : passengers)
        {
            if (it.second == destination)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << "Destination not on the way" << std::endl;
            if (!route.empty())
            {
                std::cout << "Adding to the back of the route" << std::endl;
                // get last road component
                auto last = route.back();
                // calculate route from last to destination
                std::vector<std::shared_ptr<RoadComponent>> newRoute = ccm->calculateRoute(last, destination);
                route.insert(route.end(), newRoute.begin(), newRoute.end());
            }
            else
            {
                std::cout << "No queued route" << std::endl;
                std::vector<std::shared_ptr<RoadComponent>> newRoute = ccm->calculateRoute(currentLocation, destination);
                route.insert(route.end(), newRoute.begin(), newRoute.end());
            }
        }
    }

    std::cout << "Route" << std::endl;
    for (const auto& r : route)
    {
        r->displayInfo();
    }
}

Bus::Bus(std::shared_ptr<RoadComponent> start, int capacity) : Citizen(false)
{
    name = "Bus";
    currentLocation = start;
    RoadsComposite *road = dynamic_cast<RoadsComposite *>(start.get());
    if (road != nullptr)
    {
        currentLocation = road->getConnections()[0];
    }
    if (!Policy::getBusLaw())
    {
        currentLocation->addUser(this);
    }
    this->capacity = capacity;
    busCount++;
    activity = Activity::Nothing;
    CityCentralMediator *ccm = dynamic_cast<CityCentralMediator *>(this->mediator);
    ccm->registerBus(this);
    ccm->notifyBusReady(this);
}

bool Bus::isFull()
{
    return passengers.size() == capacity;
}

void Bus::addPassenger(std::unique_ptr<Citizen> passenger, std::shared_ptr<RoadComponent> destination)
{
    recalculateRoute(destination);
    if (passengers.size() < capacity)
    {
        passengers.emplace_back(std::move(passenger), destination); // Use emplace_back with move semantics
    }
}

void Bus::removePassenger(Citizen *passenger)
{
    for (auto it = passengers.begin(); it != passengers.end(); it++)
    {
        if (it->first.get() == passenger) // Compare with raw pointer
        {
            passengers.erase(it);
            break;
        }
    }
}

void Bus::doSomething()
{
    // Check if any passengers should get off
    for (auto it = passengers.begin(); it != passengers.end(); it++)
    {
        if (it->second == currentLocation)
        {
            std::cout << "Arrived at one destination" << std::endl;
            if (it->first != nullptr)
            {
                it->first->notifyChange("Arrived_Destination");
            }
            passengers.erase(it);
            break;
        }
    }

    if (passengers.empty() && route.empty())
    {
        std::cout << "Bus is idle" << std::endl;
        CityCentralMediator *ccm = dynamic_cast<CityCentralMediator *>(this->mediator);
        ccm->notifyBusReady(this);
    }

    if (!route.empty())
    {
        std::cout << "Bus is moving" << std::endl;
        std::cout << "Current location: ";
        currentLocation->displayInfo();
        // Move buses along route
        if (!route[0]->isFull())
        {
            route[0]->addUser(this);
            currentLocation->removeUser(this);
            currentLocation = route[0];
            route.erase(route.begin());
        }
        else
        {
            std::cout << "Route is full" << std::endl;
        }
    }
}

void Bus::notifyChange(std::string message)
{
    // Handle notifications
}

std::shared_ptr<RoadComponent> Bus::getCurrentLocation()const
{
    return currentLocation;
}

Bus::~Bus()
{
    busCount--;
}
