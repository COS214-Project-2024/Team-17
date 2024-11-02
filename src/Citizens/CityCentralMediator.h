#ifndef CITYCENTRALMEDIATOR_H
#define CITYCENTRALMEDIATOR_H

#include <vector>
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

class CityCentralMediator : public CityMediator
{

private:
	/*
	@brief Stores the array of roads in the city.
	*/
	std::vector<RoadComponent *> roads;

	/*
	@brief Stores the array of buildings in the city.
	*/
	std::vector<Building *> buildings;

	/*
	@brief Stores the array of utilities in the city.
	*/
	std::vector<UtilityManager *> utilities;

	/*
	@brief Stores the array of citizens in the city.
	*/
	std::vector<Citizen *> citizens;

	/*
	@brief Stores the array of train stations in the city.
	*/
	std::vector<Trainstation *> trainStations;

	RoadState *roadState;
	std::vector<Bus *> buses;
	std::vector<Bus *> busQueue;

public:
	RoadComponent *getClosestRoad(int x, int y);

	static CityCentralMediator *getInstance();
	static const int BUILDING_ROAD_DISTANCE = 30;

	/*
	@brief Registers a building with the mediator.
	@param building The building to register.
	*/
	void registerBuilding(Building *building);

	/*
	@brief Registers a utility with the mediator.
	@param util The utility to register.
	*/
	void registerUtility(UtilityManager *util);

	/*
	@brief Registers a citizen with the mediator.
	@param citizen The citizen to register.
	*/
	void registerCitizen(Citizen *citizen);

	/*
	@brief Registers a bus with the mediator.
	@param bus The bus to register.
	 */
	void registerBus(Bus *bus);

	/*
	@brief Registers a road with the mediator.
	@param road The road to register.
	*/
	void registerRoad(RoadComponent *road);

	/*
	@brief Registers a train station with the mediator.
	@param trainStation The train station to register.
	*/
	void registerTrainStation(Trainstation *trainStation);

	/*
	@brief Notifies all citizens of a building change.
	@param building The building that changed.
	@param message The message to send to the citizens.
	*/
	void notifyBuildingChange(Building *building, std::string message);

	/*
	@brief Notifies all citizens of a utility change.
	@param type The utilities building that changed.
	@param status The new status of the utility.
	@param message The message to send to the citizens.
	*/
	void notifyUtilityChange(UtilityManager *type, bool status, std::string message);

	/*
	@brief Notifies all citizens of a road status change.
	@param status The road status that changed.
	@param message The message to send to the citizens.
	*/
	void notifyRoadChange(RoadState *status, std::string message);

	void notifyBusReady(Bus *bus);

	/*
	@brief Requests a bus for a citizen.
	@param citizen The citizen requesting the bus.
	@param location The location of the citizen.
	*/
	Bus *requestBus(Citizen *citizen, RoadComponent *location);

	/*
	@brief Constructor for the CityCentralMediator. You should not be calling this. Use getInstance() instead.
	@param param Used to show that the constructor is private.
	*/
	CityCentralMediator(std::string param = "error");

	std::vector<RoadComponent *> calculateRoute(int startX, int startY, int endX, int endY);
	std::vector<RoadComponent *> calculateRoute(RoadComponent *start, RoadComponent *end);

	bool isReachableByRoad(int x, int y);

	Trainstation *trainstationInRange(int x, int y);

	void updateBuses();

	void citizensDoSomething();

	void citizensStartWork();

	void citizensEndWork();

	~CityCentralMediator();

	void handlePopulationGrowth();

	void handleUtilityFailure();

	void updateCitizenSatisfaction();
};

#endif