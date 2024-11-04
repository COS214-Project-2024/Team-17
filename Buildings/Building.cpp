#include "Building.h"

/**
 * @class Building
 * @brief Represents a building that interacts with utilities and a mediator in a city simulation.
 * 
 * This class defines a building that can receive various utilities and handle updates 
 * from a city mediator, as well as interact with visitors like a tax and budget visitor.
 */

/**
 * @brief Constructor for the Building class.
 * 
 * @param mediator Pointer to a CityMediator object to facilitate interactions between buildings.
 * @param type The type of building (e.g., residential, commercial).
 */
Building::Building(CityMediator* mediator, string type) {
    // TODO - implement Building::Building
    throw "Not yet implemented";
}

/**
 * @brief Updates the utility status of the building.
 * 
 * @param utilityStatus Reference to a string representing the current utility status.
 */
void Building::update(string& utilityStatus) {
    // TODO - implement Building::update
    throw "Not yet implemented";
}

/**
 * @brief Receives electricity for the building.
 */
void Building::receiveElectricity() {
    // TODO - implement Building::receiveElectricity
    throw "Not yet implemented";
}

/**
 * @brief Receives water for the building.
 */
void Building::receiveWater() {
    // TODO - implement Building::receiveWater
    throw "Not yet implemented";
}

/**
 * @brief Removes waste from the building.
 */
void Building::removeWaste() {
    // TODO - implement Building::removeWaste
    throw "Not yet implemented";
}

/**
 * @brief Removes sewage from the building.
 */
void Building::removeSewage() {
    // TODO - implement Building::removeSewage
    throw "Not yet implemented";
}

/**
 * @brief Notifies the building of an outage in a specified utility.
 * 
 * @param utility Reference to a string representing the utility with an outage.
 */
void Building::notifyOutage(string& utility) {
    // TODO - implement Building::notifyOutage
    throw "Not yet implemented";
}

/**
 * @brief Notifies the building that water is unavailable.
 * 
 * @param utility Reference to a string representing the affected utility (e.g., water).
 */
void Building::notifyNoWater(string& utility) {
    // TODO - implement Building::notifyNoWater
    throw "Not yet implemented";
}

/**
 * @brief Notifies the building of waste removal.
 * 
 * @param utility Reference to a string representing the utility involved in waste removal.
 */
void Building::notifyWasteRemove(string& utility) {
    // TODO - implement Building::notifyWasteRemove
    throw "Not yet implemented";
}

/**
 * @brief Notifies the building of sewage removal.
 * 
 * @param utility Reference to a string representing the utility involved in sewage removal.
 */
void Building::notifySewageRemove(string& utility) {
    // TODO - implement Building::notifySewageRemove
    throw "Not yet implemented";
}

/**
 * @brief Gets the type of the building.
 * 
 * @return A string representing the type of the building.
 */
string Building::getType() {
    // TODO - implement Building::getType
    throw "Not yet implemented";
}

/**
 * @brief Constructs the building.
 */
void Building::construct() {
    // TODO - implement Building::construct
    throw "Not yet implemented";
}

/**
 * @brief Notifies about a change in the building state.
 */
void Building::abstract_notifyChange() {
    // TODO - implement Building::abstract_notifyChange
    throw "Not yet implemented";
}

/**
 * @brief Accepts a visitor for tax and budget purposes.
 * 
 * @param visitor Pointer to a TaxAndBudgetVisitor object to process tax and budget operations.
 */
void Building::accept(TaxAndBudgetVisitor* visitor) {
    // TODO - implement Building::accept
    throw "Not yet implemented";
}
