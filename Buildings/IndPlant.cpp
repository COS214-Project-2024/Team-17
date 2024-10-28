#include "IndPlant.h"

IndPlant::IndPlant() {
    cout << BLACK << "\t-->Plant created" << RESET << endl;
}

void IndPlant::displayBuildingInfo() {
    cout << "Plant with production capacity of " << this->productionCapacity << " units\n";
}

int IndPlant::getProductionCapacity() {
    return productionCapacity;
}

void IndPlant::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}

	void IndPlant::callUtilities(){
        notifyUtilities();
    }

	bool IndPlant::getState(){
        return operational;
    }

	void IndPlant::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string IndPlant::getBuildingType(){
        return type;
    }