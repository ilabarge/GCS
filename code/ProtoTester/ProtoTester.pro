#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T14:59:38
#
#-------------------------------------------------

QT       += core gui serialport network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProtoTester
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/protonet/rx_thread.cpp \
    src/protonet/networking.cpp

HEADERS  += mainwindow.h \
    src/protonet/include/cond.h \
    src/protonet/include/config.h \
    src/protonet/include/datalink.h \
    src/protonet/include/mutex.h \
    src/protonet/include/protonet.h \
    src/protonet/include/protonet_marshal.h \
    src/protonet/include/protonet_message.h \
    src/protonet/include/protonet_parser.h \
    src/protonet/include/protonet_protocol.h \
    src/protonet/include/queue.h \
    src/protonet/include/serial.h \
    src/protonet/include/thread.h \
    src/protonet/include/udp.h \
    src/protonet/include/message/AirVehicleGroundRelativeState.h \
    src/protonet/include/message/CommunicationPayloadCommand.h \
    src/protonet/include/message/CommunicationPayloadConfigurationCommand.h \
    src/protonet/include/message/CommunicationPayloadStatus.h \
    src/protonet/include/message/ConnectionReply.h \
    src/protonet/include/message/ConnectionRequest.h \
    src/protonet/include/message/Enter.h \
    src/protonet/include/message/Exit.h \
    src/protonet/include/message/PayloadBayCommand.h \
    src/protonet/include/message/PayloadBayModeCommand.h \
    src/protonet/include/message/PayloadBayStatus.h \
    src/protonet/include/message/PayloadDataRecorderCommand.h \
    src/protonet/include/message/PayloadDataRecorderStatus.h \
    src/protonet/include/message/PayloadOperatingStatus.h \
    src/protonet/include/message/PayloadOperationCommand.h \
    src/protonet/include/message/Ping.h \
    src/protonet/include/message/Pong.h \
    src/protonet/include/message/Raw.h \
    src/protonet/include/message/TargetDesignationCommand.h \
    src/protonet/include/message/UGVBatteryStatus.h \
    src/protonet/include/message/UGVJoystick.h \
    src/protonet/include/message/VehicleAttitude.h \
    src/protonet/include/message/VehicleAuthorizationReply.h \
    src/protonet/include/message/VehicleAuthorizationRequest.h \
    src/protonet/include/message/VehicleBodySensedState.h \
    src/protonet/include/message/VehicleGlobalPosition.h \
    src/protonet/include/message/VehicleGroundRelativeState.h \
    src/protonet/include/message/VehicleIdentification.h \
    src/protonet/include/message/VehicleInertialState.h \
    src/protonet/include/message/VehicleJoystickCommand.h \
    src/protonet/include/message/VehicleModeCommand.h \
    src/protonet/include/message/VehicleSystemStatus.h \
    src/protonet/include/message/VehicleTelemetryCommand.h \
    src/protonet/include/message/VehicleTerminationCommand.h \
    src/protonet/include/message/VehicleWaypointCommand.h \
    src/protonet/networking.h \
    src/protonet/rx_thread.h

INCLUDEPATH += $$PWD/src/protonet/include
DEPENDPATH += $$PWD/src/protonet/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonet_32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonet_32d
else:unix: LIBS += -L$$PWD/src/protonet/ -lprotonet_32

INCLUDEPATH += $$PWD/src/protonet
DEPENDPATH += $$PWD/src/protonet
