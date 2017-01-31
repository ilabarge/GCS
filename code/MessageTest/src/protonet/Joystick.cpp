
#include "Joystick.h"

// Uncomment this line to build the class without connecting to real devices
#define DUMMY_JOYSTICK

Joystick::Joystick() : device(0), autoPoll(true), buttonA(JOY_BUTTON1), buttonB(JOY_BUTTON2) {
        ZeroMemory(&joyCaps,   sizeof(joyCaps));
        ZeroMemory(&joyInfoEx, sizeof(joyInfoEx));
        joyInfoEx.dwSize = sizeof(joyInfoEx);
        setDevice(device);
}

Joystick::~Joystick() {}

int Joystick::getNumDevices() {
#ifndef DUMMY_JOYSTICK
        return joyGetNumDevs();
#else
        return 1;
#endif
}

bool Joystick::setDevice(int index) {
#ifndef DUMMY_JOYSTICK
        joyGetDevCaps(index, &joyCaps, sizeof(joyCaps));
#endif
        device = index;
        return isConnected();
}

int Joystick::getDevice() {
        return device;
}

bool Joystick::isConnected() {
#ifndef DUMMY_JOYSTICK
        return joyGetPosEx(device, &joyInfoEx) == JOYERR_NOERROR;
#else
        return true;
#endif
}

void Joystick::setAutoPoll(bool enabled) {
        if (!enabled) {
                joyInfoEx.dwFlags = JOY_RETURNBUTTONS | JOY_RETURNX | JOY_RETURNY | JOY_RETURNZ | JOY_RETURNR | JOY_RETURNU | JOY_RETURNV | JOY_RETURNPOV;
        }
        autoPoll = enabled;
}

bool Joystick::getAutoPoll() {
        return autoPoll;
}

void Joystick::poll() {
        if (!autoPoll) {
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
}

bool Joystick::hasZAxis() {
        return (joyCaps.wCaps & JOYCAPS_HASZ) != 0;
}

bool Joystick::hasRAxis() {
        return (joyCaps.wCaps & JOYCAPS_HASR) != 0;
}

bool Joystick::hasUAxis() {
        return (joyCaps.wCaps & JOYCAPS_HASU) != 0;
}

bool Joystick::hasVAxis() {
        return (joyCaps.wCaps & JOYCAPS_HASV) != 0;
}

bool Joystick::hasPOV() {
        return (joyCaps.wCaps & JOYCAPS_HASPOV) != 0;
}

int Joystick::getNumButtons() {
        return joyCaps.wNumButtons;
}

void Joystick::setButtonA(int button) {
        if (button >= 0 && button < (signed) getNumButtons()) {
                buttonA = 1 << button;
        }
}

void Joystick::setButtonB(int button) {
        if (button >= 0 && button < (signed) getNumButtons()) {
                buttonB = 1 << button;
        }
}

void Joystick::calibrate() {
        WinExec("control joy.cpl", SW_NORMAL);
}

int Joystick::getX() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNX;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwXpos;
}

int Joystick::getY() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNY;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwYpos;
}

int Joystick::getZ() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNZ;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwZpos;
}

int Joystick::getR() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNR;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwRpos;
}

int Joystick::getU() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNU;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwUpos;
}

int Joystick::getV() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNV;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwVpos;
}

bool Joystick::getA() {
        return (getButtons() & buttonA) != 0;
}

bool Joystick::getB() {
        return (getButtons() & buttonB) != 0;
}

int Joystick::getButtons() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNBUTTONS;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwButtons;
}

int Joystick::getPOV() {
        if (autoPoll) {
                joyInfoEx.dwFlags = JOY_RETURNPOV;
#ifndef DUMMY_JOYSTICK
                joyGetPosEx(device, &joyInfoEx);
#endif
        }
        return joyInfoEx.dwPOV;
}

bool Joystick::getDPad(Direction direction) {
        switch (direction) {
                case DPAD_UP:
                        return getY() < 28672;
                case DPAD_DOWN:
                        return getY() > 36864;
                case DPAD_LEFT:
                        return getX() < 28672;
                case DPAD_RIGHT:
                        return getX() > 36864;
        }
        return false;
}
