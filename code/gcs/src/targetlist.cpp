#include "targetlist.h"
#include "qdebug.h"

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
            //qDebug() << "returning target\n";
            return targets.at(i);
        }
    }
    //qDebug() << "target not found\n";
    return new Target();
}

bool TargetList::inList(int ID)
{
    for(QVector<Target*>::iterator it = targets.begin(); it!= targets.end(); ++it)
    {
//        qDebug() << "ID = " << ID;
//        qDebug() << "getTargetID = " << (*it)->getTargetID();
        if(ID == (*it)->getTargetID())
        {
            //qDebug() << "target in list";
            return true;
        }
    }
    //qDebug() << "target not in list";
    return false;
}

void TargetList::updateTarget(int targID)
{
    emit update(targID);
}

void TargetList::updateTargetDisplay(int targID)
{
    emit updateDisplay(targID);
}
