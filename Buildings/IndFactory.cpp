#include "IndFactory.h"
// Error?
// IndFactory::IndFactory() {
//     cout << BLACK << "\t-->Factory created" << RESET << endl;
// }

void IndFactory::displayBuildingInfo() {
    cout << "Factory with production capacity of " << this->productionCapacity << " units\n";
}

int IndFactory::getProductionCapacity() {
    return productionCapacity;
}

void IndFactory::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}

	void IndFactory::callUtilities(){
        notifyUtilities();
    }

	bool IndFactory::getState(){
        return operational;
    }

	void IndFactory::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string IndFactory::getBuildingType(){
        return type;
    }