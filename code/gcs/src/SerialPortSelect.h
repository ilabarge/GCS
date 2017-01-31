#ifndef SERIALPORTSELECT_H
#define SERIALPORTSELECT_H

#include <QWidget>
#include <QGridLayout>

#include "SerialCombobox.h"

class SerialPortSelect : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortSelect(QWidget *parent = 0);
    ~SerialPortSelect();

signals:
    void serialPortSelected(const QString& text);

private:
    SerialComboBox* combo;
    QGridLayout* mainLayout;

private slots:
    void indexChanged(const QString& text);
//    void indexChanged(int index);
};

#endif // SERIALPORTSELECT_H
