#ifndef SERIALCOMBOBOX_H
#define SERIALCOMBOBOX_H

#include <QComboBox>
#include <QMouseEvent>
#include <QString>
#include <QStringList>

#include "serialscanner.h"

class SerialComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit SerialComboBox(QWidget* parent = 0);
    ~SerialComboBox();

private:
    void mousePressEvent(QMouseEvent* event);

signals:
    void activated(int index);
    void currentIndexChanged(int index); //Difference between activated?
    void highlighted(int index);

public slots:
    void updateList();

};

#endif // SERIALCOMBOBOX_H
