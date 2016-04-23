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
    src/main.cpp \
    src/mainwindow.cpp \
    src/MapView.cpp \
    src/sidebar.cpp \
    src/togglebutton.cpp \
    src/gcs_toolbar.cpp \
    src/networking.cpp \
    src/rx_thread.cpp \
    src/serialscanner.cpp \
    src/nodequeue.cpp \
    src/SerialPortSelect.cpp \
    src/SerialCombobox.cpp \
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
    src/vehicle_list.cpp \
    src/consolelog.cpp \
    src/vehicleelementdisplay.cpp \
    src/vehicleinfo.cpp \
    src/MainWindowADI.cpp \
    src/WidgetADI.cpp \
    src/WidgetSix.cpp \
    src/qfi_ADI.cpp \
    src/LayoutSquare.cpp \
    src/comnet/Joystick.cpp \
    src/comnet/joystickinput.cpp \
    src/comnet/src/message/AmyStuff.cpp \
    src/comnet/src/message/Enter.cpp \
    src/comnet/src/message/Exit.cpp \
    src/comnet/src/message/PayloadBayCommand.cpp \
    src/comnet/src/message/PayloadBayModeCommand.cpp \
    src/comnet/src/message/Ping.cpp \
    src/comnet/src/message/Pong.cpp \
    src/comnet/src/message/TargetDesignationCommand.cpp \
    src/comnet/src/message/UGVBatteryStatus.cpp \
    src/comnet/src/message/UGVJoystick.cpp \
    src/comnet/src/message/VehicleAttitude.cpp \
    src/comnet/src/message/VehicleAuthorizationReply.cpp \
    src/comnet/src/message/VehicleAuthorizationRequest.cpp \
    src/comnet/src/message/VehicleBodySensedState.cpp \
    src/comnet/src/message/VehicleGlobalPosition.cpp \
    src/comnet/src/message/VehicleGroundRelativeState.cpp \
    src/comnet/src/message/VehicleIdentification.cpp \
    src/comnet/src/message/VehicleInertialState.cpp \
    src/comnet/src/message/VehicleModeCommand.cpp \
    src/comnet/src/message/VehicleSystemStatus.cpp \
    src/comnet/src/message/VehicleTelemetryCommand.cpp \
    src/comnet/src/message/VehicleTerminationCommand.cpp \
    src/comnet/src/message/VehicleWaypointCommand.cpp \
    src/comnet/src/comnet.cpp \
    src/comnet/src/comnet_marshal.cpp \
    src/comnet/src/comnet_message.cpp \
    src/comnet/src/comnet_parser.cpp \
    src/comnet/src/comnet_protocol.cpp \
    src/comnet/src/cond.cpp \
    src/comnet/src/datalink.cpp \
    src/comnet/src/mutexCom.cpp \
    src/comnet/src/pqueue.cpp \
    src/comnet/src/rand_array.cpp \
    src/comnet/src/random_numbers.cpp \
    src/comnet/src/serial.cpp \
    src/comnet/src/threadCom.cpp \
    src/comnet/src/udp.cpp \
    src/comnet/src/zigBee.cpp \
    #tests/DataValidation/testIt.cpp \
    tests/DataValidation/validateData.cpp \
    #tests/toolbar/tst_toolbartest.cpp \
    main.cpp \
    vehiclelistdisplay.cpp \
    src/messages.cpp \
    src/comnet/src/error_handle.cpp

HEADERS += \
    src/mainwindow.h \
    src/MapView.h \
    src/sidebar.h \
    src/togglebutton.h \
    src/gcs_toolbar.h \
    src/networking.h \
    src/rx_thread.h \
    src/serialscanner.h \
    src/comnet/include/cond.h \
    src/comnet/include/comnet.h \
    src/comnet/include/comnet_parser.h \
    src/comnet/include/serial.h \
    src/comnet/include/thread.h \
    src/comnet/include/udp.h \
    src/comnet/include/comnet_marshal.h \
    src/comnet/include/comnet_message.h \
    src/comnet/include/comnet_protocol.h \
    src/nodequeue.h \
    src/SerialPortSelect.h \
    src/SerialCombobox.h \
    src/comnet/joystickinput.h \ #(check usage)
    src/telemetrygui.h \
    src/waypointgui.h \
    src/vehicleauthorizationgui.h \
    src/targetinggui.h \
    src/target.h \
    src/targetlist.h \
    src/ugv_state.h \
    src/GCSGraphicsLayer.h \
    src/MapSymbol22.h \
    src/Waypoint22.h \
    src/Vehicle22.h \
    src/uavpayload.h \
    src/InternetTest.h \
    src/vehicle_list.h \
    src/consolelog.h \
    src/vehicleelementdisplay.h \
    src/vehicleinfo.h \
    src/MainWindowADI.h \
    src/qfi_ADI.h \
    src/ui_WidgetSix.h \
    src/WidgetADI.h \
    src/WidgetSix.h \
    src/comnet/include/comnet_message.h \
    src/comnet/joystickinput.h \
    src/LayoutSquare.h \
    src/comnet/include/mutexCom.h \
    src/comnet/include/pqueue.h \
    src/comnet/include/priority_queue.h \
    src/comnet/include/random_numbers.h \ 
    src/comnet/include/standard_logic.h \
    src/comnet/include/threadCom.h \
    src/comnet/include/zigBee.h \
    src/comnet/include/libxbee3-3.0.11/conn.h \
    src/comnet/include/libxbee3-3.0.11/frame.h \
    src/comnet/include/libxbee3-3.0.11/internal.h \
    src/comnet/include/libxbee3-3.0.11/ll.h \
    src/comnet/include/libxbee3-3.0.11/log.h \
    src/comnet/include/libxbee3-3.0.11/mode.h \
    src/comnet/include/libxbee3-3.0.11/mutex.h \
    src/comnet/include/libxbee3-3.0.11/net.h \
    src/comnet/include/libxbee3-3.0.11/net_callbacks.h \
    src/comnet/include/libxbee3-3.0.11/net_handlers.h \
    src/comnet/include/libxbee3-3.0.11/net_io.h \
    src/comnet/include/libxbee3-3.0.11/pkt.h \
    src/comnet/include/libxbee3-3.0.11/prepare.h \
    src/comnet/include/libxbee3-3.0.11/rx.h \
    src/comnet/include/libxbee3-3.0.11/thread.h \
    src/comnet/include/libxbee3-3.0.11/tx.h \
    src/comnet/include/libxbee3-3.0.11/xbee.h \
    src/comnet/include/libxbee3-3.0.11/xbee_int.h \
    src/comnet/include/libxbee3-3.0.11/xbeep.h \
    src/comnet/include/libxbee3-3.0.11/xsys.h \
    src/comnet/include/libxbee3-3.0.11/xsys_darwin.h \
    src/comnet/include/libxbee3-3.0.11/xsys_linux.h \
    src/comnet/include/libxbee3-3.0.11/xsys_win32.h \
    src/comnet/include/libxbee3-3.0.11/xsys_win32_winpthreads.h \
    src/comnet/include/message/AmyStuff.h \
    src/comnet/include/message/Enter.h \
    src/comnet/include/message/Exit.h \
    src/comnet/include/message/PayloadBayCommand.h \
    src/comnet/include/message/PayloadBayModeCommand.h \
    src/comnet/include/message/Ping.h \
    src/comnet/include/message/Pong.h \
    src/comnet/include/message/TargetDesignationCommand.h \
    src/comnet/include/message/UGVBatteryStatus.h \
    src/comnet/include/message/UGVJoystick.h \
    src/comnet/include/message/VehicleAttitude.h \
    src/comnet/include/message/VehicleAuthorizationReply.h \
    src/comnet/include/message/VehicleAuthorizationRequest.h \
    src/comnet/include/message/VehicleBodySensedState.h \
    src/comnet/include/message/VehicleGlobalPosition.h \
    src/comnet/include/message/VehicleGroundRelativeState.h \
    src/comnet/include/message/VehicleIdentification.h \
    src/comnet/include/message/VehicleInertialState.h \
    src/comnet/include/message/VehicleModeCommand.h \
    src/comnet/include/message/VehicleSystemStatus.h \
    src/comnet/include/message/VehicleTelemetryCommand.h \
    src/comnet/include/message/VehicleTerminationCommand.h \
    src/comnet/include/message/VehicleWaypointCommand.h \
    src/comnet/include/datalink.h \
    src/comnet/include/mutex.h \
    src/comnet/include/mutexCom.h \
    src/comnet/include/pqueue.h \
    src/comnet/include/priority_queue.h \
    src/comnet/include/random_numbers.h \
    src/comnet/include/serial.h \
    src/comnet/include/standard_logic.h \
    src/comnet/Joystick.h \
    src/comnet/joystickinput.h \
    tests/DataValidation/validate_data.h \
    vehiclelistdisplay.h \
    src/comnet/include/Joystick.h \
    src/comnet/include/joystickinput.h \
    src/comnet/include/protonet.h \
    src/comnet/include/protonet_marshal.h \
    src/comnet/include/protonet_message.h \
    src/comnet/include/protonet_parser.h \
    src/comnet/include/protonet_protocol.h \
    src/comnet/include/cryptotopp563/3way.h \
    src/comnet/include/cryptotopp563/adler32.h \
    src/comnet/include/cryptotopp563/aes.h \
    src/comnet/include/cryptotopp563/algebra.h \
    src/comnet/include/cryptotopp563/algparam.h \
    src/comnet/include/cryptotopp563/arc4.h \
    src/comnet/include/cryptotopp563/argnames.h \
    src/comnet/include/cryptotopp563/asn.h \
    src/comnet/include/cryptotopp563/authenc.h \
    src/comnet/include/cryptotopp563/base32.h \
    src/comnet/include/cryptotopp563/base64.h \
    src/comnet/include/cryptotopp563/basecode.h \
    src/comnet/include/cryptotopp563/bench.h \
    src/comnet/include/cryptotopp563/blowfish.h \
    src/comnet/include/cryptotopp563/blumshub.h \
    src/comnet/include/cryptotopp563/camellia.h \
    src/comnet/include/cryptotopp563/cast.h \
    src/comnet/include/cryptotopp563/cbcmac.h \
    src/comnet/include/cryptotopp563/ccm.h \
    src/comnet/include/cryptotopp563/channels.h \
    src/comnet/include/cryptotopp563/cmac.h \
    src/comnet/include/cryptotopp563/config.h \
    src/comnet/include/cryptotopp563/cpu.h \
    src/comnet/include/cryptotopp563/crc.h \
    src/comnet/include/cryptotopp563/cryptlib.h \
    src/comnet/include/cryptotopp563/default.h \
    src/comnet/include/cryptotopp563/des.h \
    src/comnet/include/cryptotopp563/dh.h \
    src/comnet/include/cryptotopp563/dh2.h \
    src/comnet/include/cryptotopp563/dll.h \
    src/comnet/include/cryptotopp563/dmac.h \
    src/comnet/include/cryptotopp563/dsa.h \
    src/comnet/include/cryptotopp563/eax.h \
    src/comnet/include/cryptotopp563/ec2n.h \
    src/comnet/include/cryptotopp563/eccrypto.h \
    src/comnet/include/cryptotopp563/ecp.h \
    src/comnet/include/cryptotopp563/elgamal.h \
    src/comnet/include/cryptotopp563/emsa2.h \
    src/comnet/include/cryptotopp563/eprecomp.h \
    src/comnet/include/cryptotopp563/esign.h \
    src/comnet/include/cryptotopp563/factory.h \
    src/comnet/include/cryptotopp563/files.h \
    src/comnet/include/cryptotopp563/filters.h \
    src/comnet/include/cryptotopp563/fips140.h \
    src/comnet/include/cryptotopp563/fltrimpl.h \
    src/comnet/include/cryptotopp563/gcm.h \
    src/comnet/include/cryptotopp563/gf256.h \
    src/comnet/include/cryptotopp563/gf2_32.h \
    src/comnet/include/cryptotopp563/gf2n.h \
    src/comnet/include/cryptotopp563/gfpcrypt.h \
    src/comnet/include/cryptotopp563/gost.h \
    src/comnet/include/cryptotopp563/gzip.h \
    src/comnet/include/cryptotopp563/hex.h \
    src/comnet/include/cryptotopp563/hkdf.h \
    src/comnet/include/cryptotopp563/hmac.h \
    src/comnet/include/cryptotopp563/hrtimer.h \
    src/comnet/include/cryptotopp563/ida.h \
    src/comnet/include/cryptotopp563/idea.h \
    src/comnet/include/cryptotopp563/integer.h \
    src/comnet/include/cryptotopp563/iterhash.h \
    src/comnet/include/cryptotopp563/lubyrack.h \
    src/comnet/include/cryptotopp563/luc.h \
    src/comnet/include/cryptotopp563/mars.h \
    src/comnet/include/cryptotopp563/md2.h \
    src/comnet/include/cryptotopp563/md4.h \
    src/comnet/include/cryptotopp563/md5.h \
    src/comnet/include/cryptotopp563/mdc.h \
    src/comnet/include/cryptotopp563/mersenne.h \
    src/comnet/include/cryptotopp563/misc.h \
    src/comnet/include/cryptotopp563/modarith.h \
    src/comnet/include/cryptotopp563/modes.h \
    src/comnet/include/cryptotopp563/modexppc.h \
    src/comnet/include/cryptotopp563/mqueue.h \
    src/comnet/include/cryptotopp563/mqv.h \
    src/comnet/include/cryptotopp563/nbtheory.h \
    src/comnet/include/cryptotopp563/network.h \
    src/comnet/include/cryptotopp563/nr.h \
    src/comnet/include/cryptotopp563/oaep.h \
    src/comnet/include/cryptotopp563/oids.h \
    src/comnet/include/cryptotopp563/osrng.h \
    src/comnet/include/cryptotopp563/panama.h \
    src/comnet/include/cryptotopp563/pch.h \
    src/comnet/include/cryptotopp563/pkcspad.h \
    src/comnet/include/cryptotopp563/polynomi.h \
    src/comnet/include/cryptotopp563/pssr.h \
    src/comnet/include/cryptotopp563/pubkey.h \
    src/comnet/include/cryptotopp563/pwdbased.h \
    src/comnet/include/cryptotopp563/queue.h \
    src/comnet/include/cryptotopp563/rabin.h \
    src/comnet/include/cryptotopp563/randpool.h \
    src/comnet/include/cryptotopp563/rc2.h \
    src/comnet/include/cryptotopp563/rc5.h \
    src/comnet/include/cryptotopp563/rc6.h \
    src/comnet/include/cryptotopp563/rdrand.h \
    src/comnet/include/cryptotopp563/resource.h \
    src/comnet/include/cryptotopp563/rijndael.h \
    src/comnet/include/cryptotopp563/ripemd.h \
    src/comnet/include/cryptotopp563/rng.h \
    src/comnet/include/cryptotopp563/rsa.h \
    src/comnet/include/cryptotopp563/rw.h \
    src/comnet/include/cryptotopp563/safer.h \
    src/comnet/include/cryptotopp563/salsa.h \
    src/comnet/include/cryptotopp563/seal.h \
    src/comnet/include/cryptotopp563/secblock.h \
    src/comnet/include/cryptotopp563/seckey.h \
    src/comnet/include/cryptotopp563/seed.h \
    src/comnet/include/cryptotopp563/serpent.h \
    src/comnet/include/cryptotopp563/serpentp.h \
    src/comnet/include/cryptotopp563/sha.h \
    src/comnet/include/cryptotopp563/sha3.h \
    src/comnet/include/cryptotopp563/shacal2.h \
    src/comnet/include/cryptotopp563/shark.h \
    src/comnet/include/cryptotopp563/simple.h \
    src/comnet/include/cryptotopp563/skipjack.h \
    src/comnet/include/cryptotopp563/smartptr.h \
    src/comnet/include/cryptotopp563/socketft.h \
    src/comnet/include/cryptotopp563/sosemanuk.h \
    src/comnet/include/cryptotopp563/square.h \
    src/comnet/include/cryptotopp563/stdcpp.h \
    src/comnet/include/cryptotopp563/strciphr.h \
    src/comnet/include/cryptotopp563/tea.h \
    src/comnet/include/cryptotopp563/tiger.h \
    src/comnet/include/cryptotopp563/trdlocal.h \
    src/comnet/include/cryptotopp563/trunhash.h \
    src/comnet/include/cryptotopp563/ttmac.h \
    src/comnet/include/cryptotopp563/twofish.h \
    src/comnet/include/cryptotopp563/validate.h \
    src/comnet/include/cryptotopp563/vmac.h \
    src/comnet/include/cryptotopp563/wait.h \
    src/comnet/include/cryptotopp563/wake.h \
    src/comnet/include/cryptotopp563/whrlpool.h \
    src/comnet/include/cryptotopp563/winpipes.h \
    src/comnet/include/cryptotopp563/words.h \
    src/comnet/include/cryptotopp563/xtr.h \
    src/comnet/include/cryptotopp563/xtrcrypt.h \
    src/comnet/include/cryptotopp563/zdeflate.h \
    src/comnet/include/cryptotopp563/zinflate.h \
    src/comnet/include/cryptotopp563/zlib.h \
    src/comnet/include/config.h \
    src/comnet/include/error_handle.h \
    src/messages.h


FORMS += \
    forms/gcs_toolbar.ui \
    forms/MainWindowADI.ui \
    forms/WidgetADI.ui \
    forms/WidgetSix.ui

RESOURCES += \
    images/sidebar_icons.qrc \
    images/Toolbar.qrc \
    images/resources.qrc \
    src/qfi.qrc

#Fixes qdatedime.h error
DEFINES+= NOMINMAX\
         SFML_STATIC

INCLUDEPATH += $$PWD/src/comnet/include/cryptotopp563
DEPENDPATH += $$PWD/src/comnet/include/cryptotopp563
INCLUDEPATH += $$PWD/src/comnet/include/libxbee3-3.0.11
DEPENDPATH += $$PWD/src/comnet/include/libxbee3-3.0.11
INCLUDEPATH += $$PWD/src/comnet/include
DEPENDPATH += $$PWD/src/comnet/include
INCLUDEPATH += $$PWD/src/comnet/
DEPENDPATH += $$PWD/src/comnet/
INCLUDEPATH += $$PWD/src/
DEPENDPATH += $$PWD/src/


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/comnet/ -llibxbee3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/comnet/ -llibxbee3
else:unix: LIBS += -L$$PWD/src/comnet/ -llibxbee3

INCLUDEPATH += $$PWD/src/comnet
DEPENDPATH += $$PWD/src/comnet


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/comnet/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/comnet/ -lcryptlibd
else:unix: LIBS += -L$$PWD/src/comnet/ -lcryptlib

INCLUDEPATH += $$PWD/src/comnet
DEPENDPATH += $$PWD/src/comnet


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/comnet/ -lNGCP_COM
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/comnet/ -lNGCP_COMd
else:unix: LIBS += -L$$PWD/src/comnet/ -lNGCP_COM

INCLUDEPATH += $$PWD/src/comnet
DEPENDPATH += $$PWD/src/comnet
