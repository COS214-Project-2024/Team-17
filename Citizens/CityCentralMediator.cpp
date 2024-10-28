#include "CityCentralMediator.h"

void CityCentralMediator::registerBuilding(Building* building) {
	buildings.push_back(building);
}

void CityCentralMediator::registerUtility(UtilityManager* util) {
	utilities = util;
}

void CityCentralMediator::notifyBuildingChange(Building* building) {
	for (int i = 0; i < buildings.size(); i++) {
		if (buildings[i] != building) {
			buildings[i]->notifyChange();
		}
	}
}

void CityCentralMediator::notifyUtilityChange(UtilityManager* type, bool status) {
	utilities->notifyChange();
}

void CityCentralMediator::notifyRoadChange(RoadComponent* status) {
	roadState = status;
	for (int i = 0; i < citizens.size(); i++) {
		citizens[i]->notifyChange();
	}
}

void CityCentralMediator::handlePopulationGrowth() {
	throw "Not yet implemented";
}

void CityCentralMediator::handleUtilityFailure() {
	throw "Not yet implemented";
}

void CityCentralMediator::handleTrafficStatus(RoadComponent* status) {
	throw "Not yet implemented";
}

void CityCentralMediator::updateCitizenSatisfaction() {
	throw "Not yet implemented";
}