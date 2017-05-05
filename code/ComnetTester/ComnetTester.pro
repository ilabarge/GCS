#-------------------------------------------------
#
# Project created by QtCreator 2016-03-23T15:50:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComnetTester
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    networking.cpp \
    rx_thread.cpp \

HEADERS  += mainwindow.h \
    networking.h \
    rx_thread.h \

#FORMS    += mainwindow.ui

# Include path to CommProtoPackets, which contains default packets for CommProtocol
INCLUDEPATH += $$PWD/../CommProtoPackets

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CommProtocol/build/release/ -lCommProtocol-Static
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CommProtocol/build/debug/ -lCommProtocol-Static
else:unix: LIBS += -L$$PWD/../CommProtocol/build/ -lCommProtocol-Static

INCLUDEPATH += $$PWD/../CommProtocol/CommProto/include
DEPENDPATH += $$PWD/../CommProtocol/CommProto/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/release/libCommProtocol-Static.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/debug/libCommProtocol-Static.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/release/CommProtocol-Static.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/debug/CommProtocol-Static.lib
else:unix: PRE_TARGETDEPS += $$PWD/../CommProtocol/build/libCommProtocol-Static.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CommProtocol/build/Encryption/cryptopp563/release/ -lcryptopp-static
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CommProtocol/build/Encryption/cryptopp563/debug/ -lcryptopp-static
else:unix: LIBS += -L$$PWD/../CommProtocol/build/Encryption/cryptopp563/ -lcryptopp-static

INCLUDEPATH += $$PWD/../CommProtocol/build/Encryption/cryptopp563/Debug
DEPENDPATH += $$PWD/../CommProtocol/build/Encryption/cryptopp563/Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/Encryption/cryptopp563/release/libcryptopp-static.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/Encryption/cryptopp563/debug/libcryptopp-static.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/Encryption/cryptopp563/release/cryptopp-static.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../CommProtocol/build/Encryption/cryptopp563/debug/cryptopp-static.lib
else:unix: PRE_TARGETDEPS += $$PWD/../CommProtocol/build/Encryption/cryptopp563/libcryptopp-static.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CommProtocol/build/libxbee3/release/ -llibxbee3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CommProtocol/build/libxbee3/debug/ -llibxbee3
else:unix: LIBS += -L$$PWD/../CommProtocol/build/libxbee3/ -llibxbee3

INCLUDEPATH += $$PWD/../CommProtocol/build/libxbee3/Release
DEPENDPATH += $$PWD/../CommProtocol/build/libxbee3/Release

INCLUDEPATH += $$PWD/../CommProto-MessageStandards2017/packets/cpp
