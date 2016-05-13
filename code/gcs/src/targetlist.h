#ifndef TARGETLIST_H
#define TARGETLIST_H

#include <QObject>
#include <QVector>
#include "target.h"

class TargetList : public QObject
{
    Q_OBJECT
public:
    explicit TargetList(QObject *parent = 0);
    void addTarget(Target*);
    void removeTarget(int);
    Target *getTarget(int);
    bool inList(int);

signals:
    void newTarget(Target*);

public slots:
private:
   QVector<Target*> targets;
};

#endif // TARGETLIST_H
