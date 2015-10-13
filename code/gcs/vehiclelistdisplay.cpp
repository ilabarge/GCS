#include "vehiclelistdisplay.h"

VehicleListDisplay::VehicleListDisplay(QWidget *parent) :
    QWidget(parent)
{
}

//Sets the local vehicle pointer list
void VehicleListDisplay::setList(vehicle_list *list){
    vList = list;
    for(int i = 0; i < list->length(); i++){
        VehicleElementDisplay *element = new VehicleElementDisplay();
        element->setVehicle(vlist->at(i));
        vehicleList->add(element);
    }
    return;
}

/**
 * @brief VehicleListDisplay::updateDisplay
 * Updates the display with the given id
 * @param id id of the vehicle to update
 */
void VehicleListDisplay::updateDisplay(int id){

}

