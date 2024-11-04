#ifndef CITYCENTRALMEDIATOR_H
#define CITYCENTRALMEDIATOR_H

#include <vector>
#include <memory> // For smart pointers
#include "CityMediator.h"
#include "Citizen.h"
#include <string>

class Building;
class UtilityManager;
class RoadState;
class RoadComponent;
class RoadIterator;
class Bus;
class Trainstation;
class Services;
class TaxAndBudgetVisitor;

/**
 * @class CityCentralMediator
 * @brief Mediator class that facilitates communication between various city components.
 *
 * The CityCentralMediator class acts as an intermediary, coordinating interactions
 * between buildings, utilities, citizens, buses, and train stations.
 * It ensures that all components can communicate and respond to changes
 * within the city ecosystem.
 */
class CityCentralMediator : public CityMediator
{

private:
    /*
    @brief Stores the array of roads in the city.
    */
    std::vector<std::shared_ptr<RoadComponent>> roads;

    /*
    @brief Stores the array of buildings in the city.
    */
    std::vector<std::shared_ptr<Building>> buildings;

    /*
    @brief Stores the array of utilities in the city.
    */
    std::vector<std::shared_ptr<UtilityManager>> utilities;

    /*
    @brief Stores the array of citizens in the city.
    */
    std::vector<std::shared_ptr<Citizen>> citizens;

    /*
    @brief Stores the array of train stations in the city.
    */
    std::vector<std::shared_ptr<Trainstation>> trainStations;

    std::shared_ptr<RoadState> roadState;
    std::vector<std::shared_ptr<Bus>> buses;
    std::vector<std::shared_ptr<Bus>> busQueue;

    void checkCitizenServiceSatisfaction();

public:
    static CityCentralMediator* getInstance();
    static const int BUILDING_ROAD_DISTANCE = 30;

    /*
    @brief Registers a building with the mediator.
    @param building The building to register.
    */
    void registerBuilding(std::shared_ptr<Building> building);

    /*
    @brief Registers a utility with the mediator.
    @param util The utility to register.
    */
    void registerUtility(std::shared_ptr<UtilityManager> util);

    /*
    @brief Registers a citizen with the mediator.
    @param citizen The citizen to register.
    */
    void registerCitizen(std::shared_ptr<Citizen> citizen);

    /*
    @brief Registers a bus with the mediator.
    @param bus The bus to register.
    */
    void registerBus(std::shared_ptr<Bus> bus);

    /*
    @brief Registers a road with the mediator.
    @param road The road to register.
    */
    void registerRoad(std::shared_ptr<RoadComponent> road);

    /*
    @brief Registers a train station with the mediator.
    @param trainStation The train station to register.
    */
    void registerTrainStation(std::shared_ptr<Trainstation> trainStation);

    /*
    @brief Notifies all citizens of a building change.
    @param building The building that changed.
    @param message The message to send to the citizens.
    */
    void notifyBuildingChange(std::shared_ptr<Building> building, const std::string& message);

    /*
    @brief Notifies all citizens of a utility change.
    @param type The utilities building that changed.
    @param status The new status of the utility.
    @param message The message to send to the citizens.
    */
    void notifyUtilityChange(std::shared_ptr<UtilityManager> type, bool status, const std::string& message);

    /*
    @brief Notifies all citizens of a Services change.
    @param type The services building that changed.
    @param message The message to send to the citizens.
    */
    void notifyServicesChange(std::shared_ptr<Services> type, const std::string& message);

    /*
    @brief Notifies all citizens of a road status change.
    @param status The road status that changed.
    @param message The message to send to the citizens.
    */
    void notifyRoadChange(std::shared_ptr<RoadState> status, const std::string& message);

    /*
    @brief Notifies all citizens of a policy change.
    @param message The message to send to the citizens.
    */
    void notifyPolicyChange(const std::string& message);

    void notifyBusReady(std::shared_ptr<Bus> bus);

    /*
    @brief Requests a bus for a citizen.
    @param citizen The citizen requesting the bus.
    @param location The location of the citizen.
    */
    std::shared_ptr<Bus> requestBus(std::shared_ptr<Citizen> citizen, std::shared_ptr<RoadComponent> location);

    /*
    @brief Constructor for the CityCentralMediator. You should not be calling this. Use getInstance() instead.
    @param param Used to show that the constructor is private.
    */
    CityCentralMediator(std::string param = "error");

    std::vector<std::shared_ptr<RoadComponent>> calculateRoute(int startX, int startY, int endX, int endY);
    std::vector<std::shared_ptr<RoadComponent>> calculateRoute(std::shared_ptr<RoadComponent> start, std::shared_ptr<RoadComponent> end);

    bool isReachableByRoad(int x, int y);

    std::shared_ptr<Trainstation> trainstationInRange(int x, int y);

    std::shared_ptr<Building> requestJob();

    void updateBuses();

    void citizensDoSomething();

    void citizensStartWork();

    void updateJobs();

    void citizensEndWork();

    ~CityCentralMediator();

    void handlePopulationGrowth();

    void handleUtilityFailure();

    void updateCitizenSatisfaction();

    double accept(TaxAndBudgetVisitor* visitor);

    void handleCitizenEmigration(std::shared_ptr<Citizen> citizen);
};

#endif
