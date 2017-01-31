#include "nodequeue.h"

NodeQueue::NodeQueue(QObject *parent) :
    QObject(parent)
{
}

void NodeQueue::enqueue(int node)
{
   vQueue.enqueue(node);
   emit update_queue();
}

void NodeQueue::status(int vech, int stat){ emit vechStat(vech,stat); }

bool NodeQueue::isEmpty(){ return vQueue.isEmpty();}

int NodeQueue::dequeue(){ return vQueue.dequeue();}

void NodeQueue::targetRec(float lat, float longi) { emit target(lat,longi);}
