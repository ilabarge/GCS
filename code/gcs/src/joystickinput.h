#ifndef JOYSTICKINPUT_H
#define JOYSTICKINPUT_H

//QT Includes
#include <QObject>
#include <QDebug>

//GCS Includes
#include <comnet/include/comnet.h>
#include <Joystick.h>

class JoystickInput : public QObject
{
    Q_OBJECT
public:
    explicit JoystickInput(QObject *parent = 0,comnet::node* = NULL);
    boolean send;

signals:

public slots:
    void process();
    void stop();

private:
    comnet::node* node;

};
/*
enum InputType
{
    JoystickInput
};

struct MyKeys
{
    InputType myInputType;
    sf::Event::EventType myEventType;
};*/
#endif // JOYSTICKINPUT_H
