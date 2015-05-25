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
//Returns vehicle at the position in the vector
Vehicle22* vehicle_list::at(int pos)
{
    qDebug() << "at vechID" << pos;
    //If vehicle not found
    if(pos < 0 || pos > vlist.size() - 1)
    {
      qDebug() << "No such vehicle at pos" << pos;
      //Notify user
      //emit incorrectPos(pos);
      return 0;
    }
      else
        return vlist.at(pos);
}

/**
 * @brief vehicle_list::set Returns a pointer to the vehicle
 * @param vechID ID of the vehicle we want
 * @return the values of vehicle whose id we have, notifies user if incorrect
 * id was given
 */
Vehicle22 *vehicle_list::set(int vechID)
{
    qDebug() << "SET";
    int ndx = indexOf(vechID);
    //If vehicle not found
    if(ndx == -1)
    {
      qDebug() << "No such vehicle" << vechID;
      //Notify user
      emit incorrect(vechID);
      return 0;
    }
    else
    {
        //We emit an update when we update information
        //emit update(vechID);
        return vlist.at(ndx);
    }
}

/**
 * @brief vehicle_list::set Returns a pointer to the vehicle
 * @param vechID ID of the vehicle we want
 * @return the values of vehicle whose id we have, notifies user if incorrect
 * id was given
 */
//Returns the vechicle with the id given
Vehicle22 *vehicle_list::get(int vechID)
{
    qDebug() << "GET";
    int ndx = indexOf(vechID);
    //If vehicle not found
    if(ndx == -1)
    {
      qDebug() << "No such vehicle" << vechID;
      //Notify user
      //emit incorrect(vechID);
      return 0;
    }
    else
    {
        return vlist.at(ndx);
    }
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
    qDebug() << "Adding vehicle ID" << val;
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
    qDebug() << "Looking for vehcile ID " << id;
//    for(std::vector<int>::iterator it = pos.begin(); it!= pos.end(); ++it)
//    {
//        if(id == *it)
//            return p;
//        p++;
//        qDebug() << p;
//    }
    for(std::vector<Vehicle22*>::iterator it = vlist.begin(); it!= vlist.end(); ++it)
    {
        if(id == (*it)->getVehicleID())
        {
            qDebug() << "FOUND POSITION FOR ID " << id << "," << p;
            return p;
        }
        //qDebug() <<  "ID" << (*it)->getVehicleID() << "pos " << p;
        p++;
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
void vehicle_list::updateVech(int vechID)
{
    emit update(vechID);
}


bool vehicle_list::inList(int ID)
{
    qDebug() << "vehicle_list: IS" << ID << "INLIST?";
    for(std::vector<Vehicle22*>::iterator it = vlist.begin(); it!= vlist.end(); ++it)
    {
        if(ID == (*it)->getVehicleID())
        {
            qDebug() << ID << "IS IN LIST";
            return true;
        }
        //qDebug() <<  "ID" << (*it)->getVehicleID() << "pos " << p;
    }
    return false;
}
