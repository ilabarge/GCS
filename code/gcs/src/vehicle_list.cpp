#include "vehicle_list.h"

vehicle_list::vehicle_list(QObject *parent) : QObject(parent)
{
}

/**
 * @brief vehicle_list::get Returns a const to the vehicle
 * @param vechID ID of the vehicle that we want to get
 * @return the values of vehicle whose id we have, notifies user if incorrect
 * id was given
 */
Vehicle22* vehicle_list::at(int vechID)
{
//    int ndx = indexOf(vechID);
//    qDebug() << vechID;
//    //If vehicle not found
//    if(ndx == 0)
//    {
//      qDebug() << "No such vehicle";
//      //Notify user
//      emit incorrect(vechID);
//      return 0;
//    }
//      else
//        return vlist->at(ndx);
    return vlist.at(vechID);
}

/**
 * @brief vehicle_list::set Returns a pointer to the vehicle
 * @param vechID ID of the vehicle we want
 * @return the values of vehicle whose id we have, notifies user if incorrect
 * id was given
 */
Vehicle22 *vehicle_list::set(int vechID)
{
//    int ndx = indexOf(vechID);
//    //If vehicle not found
//    if(ndx == 0)
//    {
//      qDebug() << "No such vehicle";
//      //Notify user
//      emit incorrect(vechID);
//      return 0;
//    }
//    else
//    {
//        //We emit an update when we update information
//        emit update(vechID);
//        return vlist->at(ndx);
//    }
    return vlist.at(vechID);
}

/**
 * @brief vehicle_list::append Appends a vehicle to the interior vector
 * @param vech the vehicle to be added
 */
void vehicle_list::append(Vehicle22 *vech)
{
    vlist.push_back(vech);
    int val = vech->getVehicleID();
    pos.push_back(val);
    return;
}

/**
 * @brief vehicle_list::length Returns the length of the vehicle list
 * @return value of the length of the list
 */
int vehicle_list::length()
{
    return vlist.size();
}

/**
 * @brief vehicle_list::indexOf Returns the value of the index of the vehicle
 * @param id ID to find index
 * @return Index of vehicle in list
 */
int vehicle_list::indexOf(int id)
{
    int p = 0;
    for(std::vector<int>::iterator it = pos.begin(); it!= pos.end(); ++it)
    {
        if(id == *it)
            return p;
        p++;
        qDebug() << p;
    }
    return -1;
}

/**
 * @brief vehicle_list::list Returns pointer to list for access
 * @return Pointer to the vehicle list
 */
std::vector<Vehicle22*> vehicle_list::list()
{
    return vlist;
}

/**
 * @brief vehicle_list::update Emits the update to notify of the change of the vehicle at position
 * @param position The position of the vehicle to update
 */
void vehicle_list::updateVech(int position)
{
    emit update(position);
}
