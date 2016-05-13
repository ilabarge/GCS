#include "targetlist.h"

TargetList::TargetList(QObject *parent) :
    QObject(parent)
{
}

//adds a new target to the list
void TargetList::addTarget(Target* t)
{
     targets.append(t);
     emit newTarget(targets.at(targets.length() - 1));
}


//Removes a target via its id
void TargetList::removeTarget(int x)
{
    for(int i = 0; i < targets.length(); i++)
    {
        if(targets.at(i)->getTargetID() == x)
        {
            targets.removeAt(i);
            break;
        }
    }
}

//Returns target via its id, if target is
//not present, return new Target
//need to fix return issues
Target *TargetList::getTarget(int x)
{
    for(int i = 0; i < targets.length(); i++)
    {
        if(targets.at(i)->getTargetID() == x)
        {
            return targets.at(i);
        }
    }
    return new Target();
}

bool TargetList::inList(int ID)
{
    for(QVector<Target*>::iterator it = targets.begin(); it!= targets.end(); ++it)
    {
        if(ID == (*it)->getTargetID())
        {
            return true;
        }
    }
    return false;
}

