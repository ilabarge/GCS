#pragma once

#include <windows.h>
#include <mmsystem.h>

class Joystick
{
public:
        Joystick();             // creates a new instance defaulting to device 0
        ~Joystick();

        int getNumDevices();                    // returns the number of devices supported by the joystick driver
        bool setDevice(int index);              // sets the hardware device index this instance reads from, returning true if a stick or pad is connected
        int getDevice();                                // returns the hardware device index this instance is reading from
        bool isConnected();                             // returns true if a stick or pad is connected
        void setAutoPoll(bool enabled); // true if each button read (e.g. getX) should automatically poll
        bool getAutoPoll();                             // returns the auto-poll setting
        void poll();                                    // when auto-poll is false, reads and stores the button states for the device
        bool hasZAxis();                                // returns true if the device supports a z-axis
        bool hasRAxis();                                // returns true if the device supports a r-axis
        bool hasUAxis();                                // returns true if the device supports a u-axis
        bool hasVAxis();                                // returns true if the device supports a v-axis
        bool hasPOV();                                  // returns true if the device supports a hat-switch
        int getNumButtons();                    // returns the number of buttons (as in A, B, X, Y, start, etc.)
        void setButtonA(int button);    // sets the button index associated with getA()
        void setButtonB(int button);    // sets the button index associated with getB()
        void calibrate();                               // shows the system dialog for calibrating an analog device

        enum Direction {        // choices for getDPad
                DPAD_UP,
                DPAD_DOWN,
                DPAD_LEFT,
                DPAD_RIGHT
        };

        int getX();                     // returns the x-axis (0-65535)
        int getY();                     // returns the y-axis (0-65535)
        int getZ();                     // returns the (optional) z-axis (0-65535)
        int getR();                     // returns the (optional) r-axis (0-65535)
        int getU();                     // returns the (optional) u-axis (0-65535)
        int getV();                     // returns the (optional) v-axis (0-65535)
        bool getA();            // returns true if the buttons assigned to A is pressed (default is button 0)
        bool getB();            // returns true if the buttons assigned to B is pressed (default is button 1)
        int getButtons();       // returns the state of all buttons as bitmask
        int getPOV();           // returns the postion of the hat-switch
        bool getDPad(Direction direction);      // returns if a dpad direction is pressed
private:
        int device;             // currently connected device index
        bool autoPoll;  // true if each button read (e.g. getX) should automatically poll
        int buttonA;    // button index assigned to button A
        int buttonB;    // button index assigned to button B

        JOYINFOEX joyInfoEx;    // current device state
        JOYCAPS joyCaps;                // current device capabilities
};

