#include "IndWarehouse.h"

IndWarehouse::IndWarehouse() {
    cout << BLACK << "\t-->Warehouse created" << RESET << endl;
}

void IndWarehouse::displayBuildingInfo() {
    cout << "Warehouse with production capacity of " << this->productionCapacity << " units\n";
}

int IndWarehouse::getProductionCapacity() {
    return productionCapacity;
}

void IndWarehouse::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}

	void IndWarehouse::callUtilities(){
        notifyUtilities();
    }

	bool IndWarehouse::getState(){
        return operational;
    }

	void IndWarehouse::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string IndWarehouse::getBuildingType(){
        return type;
    }