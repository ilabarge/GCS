#include "joystickinput.h"
#include <stdlib.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <QDateTime>
JoystickInput::JoystickInput(QObject *parent, comnet::node *n) :
    QObject(parent)
{
    send = false;
    node = n;
}

void JoystickInput::process()
{
    //Ajay Joystick
     //qDebug() << "process" << send;
     Joystick *joystick = new Joystick();
     bool hold = false;
     QDateTime local(QDateTime::currentDateTime());
     QDateTime UTC(local.toUTC());
     float64_t time = UTC.toMSecsSinceEpoch();
     while(send)
     {
         QDateTime local2(QDateTime::currentDateTime());
         QDateTime UTC2(local2.toUTC());
         float64_t time2 = UTC2.toMSecsSinceEpoch();

        if(time2 - time > 250)
         {
            time = time2;
            //qDebug() << time;

             int y = joystick->getY();
             int z = joystick->getZ();
             if((y > 30000) && (y < 35000))
             {
                 y = 32767;
             }

             if((z > 30000) && (z < 35000))
             {
                 //qDebug() << "z is" << z;
                 z = 32767;
             }

             if((z != 32767) || (y != 32767))
             {
                 qDebug() << "send is" << send <<  "z: " << z << "y: " << y;
                 node->send_UGV_joystick(46,time2,46,z,65535-y);
                 hold = false;
             }
             else if(((z == 32767) && (y == 32767) && (hold == false)))
              {

                 qDebug() << "send is" << send <<  "z: " << z << "y: " << y;
                 node->send_UGV_joystick(46,time2,46,z,65535-y);

                 hold = true;
              }
         }
     }
     /*
    qDebug() << "started ugv";
        //SFML joystick

    joystick = new sf::Joystick();
           int i = 0;
       while(true)
       {
           qDebug() << "check while loo " << i;
          if(joystick->isConnected(0))
          {
          joystick->sf::Joystick::update();
          int y_position = sf::Joystick::getAxisPosition(0,sf::Joystick::Y);
          int z_position = sf::Joystick::getAxisPosition(0,sf::Joystick::Z);
          //Conversion to Raw Joystick input in order to send through comnet
          int y = (y_position + 100) * 327;
          int z = (z_position + 100) * 327;
          //Range for resting point for joystick
          if(y > 30739 && y < 34795)
          {
              y = 32767;
          }

          if(z > 30739 && z < 34795)
          {
              z = 32767;
          }
          node->send_UGV_joystick(42,42,z,65535 - y);
          }
          else
              qDebug() << "joystick not ocnnected";
        if(i == 100)
            break;
       }
   */
}

void JoystickInput::stop()
{
    qDebug() << "changed bool";
    send = false;
}
