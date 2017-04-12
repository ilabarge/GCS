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

QT += core gui opengl xml network serialport sql qml
QT += positioning sensors svg

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

CONFIG += c++11 esri_runtime_qt10_2_6

win32:CONFIG += \
  embed_manifest_exe
  console

SOURCES += \
    src/consolelog.cpp \
    src/gcs_toolbar.cpp \
    src/GCSGraphicsLayer.cpp \
    src/InternetTest.cpp \
    src/LayoutSquare.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/MainWindowADI.cpp \
    src/MapSymbol22.cpp \
    src/MapView.cpp \
    src/networking.cpp \
    src/nodequeue.cpp \
    src/qfi_ADI.cpp \
    src/rx_thread.cpp \
    src/SerialCombobox.cpp \
    src/SerialPortSelect.cpp \
    src/serialscanner.cpp \
    src/sidebar.cpp \
    src/target.cpp \
    src/targetinggui.cpp \
    src/targetlist.cpp \
    src/telemetrygui.cpp \
    src/togglebutton.cpp \
    src/uavpayload.cpp \
    src/ugv_state.cpp \
    src/Vehicle22.cpp \
    src/vehicle_list.cpp \
    src/vehicleauthorizationgui.cpp \
    src/vehicleelementdisplay.cpp \
    src/vehicleinfo.cpp \
    src/Waypoint22.cpp \
    src/waypointgui.cpp \
    src/WidgetADI.cpp \
    src/WidgetSix.cpp \
    #tests/DataValidation/testIt.cpp \
    tests/DataValidation/validateData.cpp \
    #tests/toolbar/tst_toolbartest.cpp \
    main.cpp \
    vehiclelistdisplay.cpp \
    src/targetinfo.cpp \
    src/Joystick.cpp \
    src/joystickinput.cpp \
    mainwindow2.cpp


HEADERS += \
    src/consolelog.h \
    src/gcs_toolbar.h \
    src/GCSGraphicsLayer.h \
    src/InternetTest.h \
    src/LayoutSquare.h \
    src/mainwindow.h \
    src/MainWindowADI.h \
    src/MapSymbol22.h \
    src/MapView.h \
    src/networking.h \
    src/nodequeue.h \
    src/qfi_ADI.h \
    src/rx_thread.h \
    src/SerialCombobox.h \
    src/SerialPortSelect.h \
    src/serialscanner.h \
    src/sidebar.h \
    src/target.h \
    src/targetinggui.h \
    src/targetlist.h \
    src/telemetrygui.h \
    src/togglebutton.h \
    src/uavpayload.h \
    src/ugv_state.h \
    src/ui_WidgetSix.h \
    src/Vehicle22.h \
    src/vehicle_list.h \
    src/vehicleauthorizationgui.h \
    src/vehicleelementdisplay.h \
    src/vehicleinfo.h \
    src/Waypoint22.h \
    src/waypointgui.h \
    src/WidgetADI.h \
    src/WidgetSix.h \
    tests/DataValidation/validate_data.h \
    vehiclelistdisplay.h \
    src/targetinfo.h \
    src/Joystick.h \
    src/joystickinput.h \
    mainwindow2.h


FORMS += \
    forms/gcs_toolbar.ui \
    forms/WidgetADI.ui \
    forms/WidgetSix.ui \
    forms/MainWindowADI.ui \
    mainwindow2.ui

RESOURCES += \
    images/sidebar_icons.qrc \
    images/Toolbar.qrc \
    images/resources.qrc \
    src/qfi.qrc

#Fixes qdatedime.h error
DEFINES+= NOMINMAX\
         SFML_STATIC

INCLUDEPATH += $$PWD/src/
DEPENDPATH += $$PWD/src/

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

INCLUDEPATH += $$PWD/../CommProtocol/build/libxbee3/Debug
DEPENDPATH += $$PWD/../CommProtocol/build/libxbee3/Debug
