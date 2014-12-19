#ifndef VEHICLE_LIST_H
#define VEHICLE_LIST_H
#include <Vehicle22.h>
#include <qdebug.h>
#include <vector>
#include <Qobject>
class vehicle_list : public QObject
{
    Q_OBJECT
public:
    explicit vehicle_list(QObject *parent = 0);
    Vehicle22 *at(int);
    Vehicle22 *set(int);
    QVector<int> getList();
    std::vector<Vehicle22 *> list();
    void append(Vehicle22 *);
    int length();

signals:
    //Vehicle id to update
    void update(int);
    void incorrect(int);

private:
    std::vector<Vehicle22*> vlist;
    std::vector<int> pos;
    int indexOf(int);
};

#endif // VEHICLE_LIST_H
