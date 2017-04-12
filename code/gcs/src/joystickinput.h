#ifndef JOYSTICKINPUT_H
#define JOYSTICKINPUT_H

//QT Includes
#include <QObject>
#include <QDebug>

//CommProtocol includes
#include <CommProto/commproto.h>

/*
//GCS Includes
#include <Joystick.h>

class JoystickInput : public QObject
{
    Q_OBJECT
public:
    explicit JoystickInput(QObject *parent = 0,comnet::node* = NULL);
    bool send;

signals:

public slots:
    void process();
    void stop();

private:
    comnet::node* node;

};

enum InputType
{
    JoystickInput
};

struct MyKeys
{
    InputType myInputType;
    sf::Event::EventType myEventType;
};
*/
#endif // JOYSTICKINPUT_H
