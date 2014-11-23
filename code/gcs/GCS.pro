#-------------------------------------------------
#  Copyright 2013 ESRI
#
#  All rights reserved under the copyright laws of the United States
#  and applicable international laws, treaties, and conventions.
#
#  You may freely redistribute and use this sample code, with or
#  without modification, provided you include the original copyright
#  notice and use restrictions.
#
#  See the Sample code usage restrictions document for further information.
#-------------------------------------------------

TARGET = GCS 
TEMPLATE = app

QT += core gui opengl xml network serialport sql

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

CONFIG += c++11 esri_runtime_qt_10_2_3

win32:CONFIG += \
  embed_manifest_exe
  console

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/MapView.cpp \
    src/sidebar.cpp \
    src/togglebutton.cpp \
    src/gcs_toolbar.cpp \
    src/protonet/networking.cpp \
    src/protonet/rx_thread.cpp \
    src/protonet/serialscanner.cpp \
    src/nodequeue.cpp \
    src/SerialPortSelect.cpp \
    src/SerialCombobox.cpp \
    src/database/DataDaemon.cpp \
    src/protonet/joystickinput.cpp \
    src/telemetrygui.cpp \
    src/waypointgui.cpp \
    src/vehicleauthorizationgui.cpp \
    src/targetinggui.cpp \
    src/target.cpp \
    src/targetlist.cpp \
    src/ugv_state.cpp \
    src/GCSGraphicsLayer.cpp \
    src/MapSymbol22.cpp \
    src/Waypoint22.cpp \
    src/Vehicle22.cpp \
    src/uavpayload.cpp \
    src/InternetTest.cpp \
    src/protonet/Joystick.cpp

HEADERS += \
    src/mainwindow.h \
    src/MapView.h \
    src/sidebar.h \
    src/togglebutton.h \
    src/gcs_toolbar.h \
    src/protonet/networking.h \
    src/protonet/rx_thread.h \
    src/protonet/serialscanner.h \
    src/protonet/include/cond.h \
    src/protonet/include/config.h \
    src/protonet/include/datalink.h \
    src/protonet/include/mutex.h \
    src/protonet/include/protonet.h \
    src/protonet/include/protonet_parser.h \
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
    src/protonet/include/message/PayloadBayStatus.h \
    src/protonet/include/message/PayloadDataRecorderCommand.h \
    src/protonet/include/message/PayloadDataRecorderStatus.h \
    src/protonet/include/message/PayloadOperatingStatus.h \
    src/protonet/include/message/PayloadOperationCommand.h \
    src/protonet/include/message/Ping.h \
    src/protonet/include/message/Pong.h \
    src/protonet/include/message/Raw.h \
    src/protonet/include/message/TargetDesignationCommand.h \
    src/protonet/include/message/UGVJoystick.h \
    src/protonet/include/message/VehicleAttitude.h \
    src/protonet/include/message/VehicleAuthorizationReply.h \
    src/protonet/include/message/VehicleAuthorizationRequest.h \
    src/protonet/include/message/VehicleBodySensedState.h \
    src/protonet/include/message/VehicleGlobalPosition.h \
    src/protonet/include/message/VehicleIdentification.h \
    src/protonet/include/message/VehicleInertialState.h \
    src/protonet/include/message/VehicleJoystickCommand.h \
    src/protonet/include/message/VehicleModeCommand.h \
    src/protonet/include/message/VehicleSystemStatus.h \
    src/protonet/include/message/VehicleTelemetryCommand.h \
    src/protonet/include/message/VehicleTerminationCommand.h \
    src/protonet/include/message/VehicleWaypointCommand.h \
    src/nodequeue.h \
    src/SerialPortSelect.h \
    src/SerialCombobox.h \
    src/database/DataDaemon.h \
    src/protonet/SFML/System.hpp \
    src/protonet/SFML/Window.hpp \
    src/protonet/SFML/Window/Joystick.hpp \
    src/protonet/SFML/Window/Window.hpp \
    src/protonet/joystickinput.h \
    src/protonet/SFML/Window/Export.hpp \
    src/protonet/SFML/Config.hpp \
    src/telemetrygui.h \
    src/waypointgui.h \
    src/vehicleauthorizationgui.h \
    src/targetinggui.h \
    src/target.h \
    src/targetlist.h \
    src/protonet/include/protonet_marshal.h \
#    src/protonet/include/protonet_message.h \
    src/protonet/include/protonet_protocol.h \
    src/protonet/include/message/PayloadBayModeCommand.h \
    src/protonet/include/message/UGVBatteryStatus.h \
    src/protonet/include/message/VehicleGroundRelativeState.h \
    src/ugv_state.h \
    src/GCSGraphicsLayer.h \
    src/MapSymbol22.h \
    src/Waypoint22.h \
    src/Vehicle22.h \
    src/uavpayload.h \
    src/InternetTest.h \
    src/protonet/Joystick.h

FORMS += \
    forms/gcs_toolbar.ui

RESOURCES += \
    gcs_sidebar/src/icons.qrc \
    gcs_toolbar.qrc \
    resources.qrc

#Fixes qdatedime.h error
DEFINES+= NOMINMAX\
         SFML_STATIC


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonet_32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonet_32d
else:unix: LIBS += -L$$PWD/src/protonet/ -lprotonet_64

INCLUDEPATH += $$PWD/src/protonet
DEPENDPATH += $$PWD/src/protonet


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonet_64
#comment upper line and decomment lower line to compile release 32bit
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonet_32
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/protonet/ -lprotonetd
#else:unix: LIBS += -L$$PWD/src/protonet/ -lprotonet

INCLUDEPATH += $$PWD/src/protonet/include
DEPENDPATH += $$PWD/src/protonet/include
INCLUDEPATH += $$PWD/src/protonet/
DEPENDPATH += $$PWD/src/protonet/
INCLUDEPATH += $$PWD/src/
DEPENDPATH += $$PWD/src/


#not using SFML
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/protonet/SFML/ -lsfml-system-s
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/protonet/SFML/ -lsfml-system-s-d
else:unix: LIBS += -L$$PWD/src/protonet/SFML/ -lsfml-system-s

INCLUDEPATH += $$PWD/src/protonet/SFML
DEPENDPATH += $$PWD/src/protonet/SFML


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/protonet/SFML/ -lsfml-window-s
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/protonet/SFML/ -lsfml-window-s-d
else:unix: LIBS += -L$$PWD/src/protonet/SFML/ -lsfml-window-s

INCLUDEPATH += $$PWD/src/protonet/SFML/Window
DEPENDPATH += $$PWD/src/protonet/SFML/Window



