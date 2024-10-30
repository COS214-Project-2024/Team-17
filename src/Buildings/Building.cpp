#include "Building.h"
#include "../Citizens/CityCentralMediator.h"

// Observer Design Pattern
// Building::Building(CityMediator* mediator, string type) : CityBlock(mediator) {
// 	this->mediator = mediator;
// 	this->name = type;
// }

Building::Building(string type) : CityBlock()
{
    this->mediator = CityCentralMediator::getInstance();
    this->name = type;
}

string Building::getBuildingType()
{
    return name;
}

void Building::notifyChange(std::string message)
{
    mediator->notifyBuildingChange(this, message);
}

void Building::accept(TaxAndBudgetVisitor *visitor)
{
    // no clue  what this is
}

// // void Building::receiveElectricity() {
// // 	// TODO - implement Building::receiveElectricity
// // 	throw "Not yet implemented";
// // }

// // void Building::receiveWater() {
// // 	// TODO - implement Building::receiveWater
// // 	throw "Not yet implemented";
// // }

// // void Building::removeWaste() {
// // 	// TODO - implement Building::removeWaste
// // 	throw "Not yet implemented";
// // }

// // void Building::removeSewage() {
// // 	// TODO - implement Building::removeSewage
// // 	throw "Not yet implemented";
// // }

// // void Building::notifyOutage(string& utility) {
// // 	// TODO - implement Building::notifyOutage
// // 	throw "Not yet implemented";
// // }

// // void Building::notifyNoWater(string& utility) {
// // 	// TODO - implement Building::notifyNoWater
// // 	throw "Not yet implemented";
// // }

// // void Building::notifyWasteRemove(string& utility) {
// // 	// TODO - implement Building::notifyWasteRemove
// // 	throw "Not yet implemented";
// // }

// // void Building::notifySewageRemove(string& utility) {
// // 	// TODO - implement Building::notifySewageRemove
// // 	throw "Not yet implemented";
// // }

// // string Building::getType() {
// // 	// TODO - implement Building::getType
// // 	throw "Not yet implemented";
// // }

// // void Building::construct() {
// // 	// TODO - implement Building::construct
// // 	throw "Not yet implemented";
// // }

// // void Building::notifyChange() {
// // 	// TODO - implement Building::abstract notifyChange
// // 	throw "Not yet implemented";
// // }

// // void Building::accept(TaxAndBudgetVisitor* visitor) {
// // 	// TODO - implement Building::accept
// // 	throw "Not yet implemented";
// // }
