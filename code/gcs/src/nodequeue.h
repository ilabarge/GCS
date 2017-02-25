#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include <QObject>
#include <QQueue>
class NodeQueue : public QObject
{
    Q_OBJECT
public:
    explicit NodeQueue(QObject *parent = 0);
    void enqueue(int);
    bool isEmpty();
    int dequeue();
    void status(int,int);
    void targetRec(float,float);

signals:
   void update_queue();
   void vechStat(int,int);
   void target(float,float);

public slots:

private:
   QQueue<int> vQueue;

};

#endif // NODEQUEUE_H
