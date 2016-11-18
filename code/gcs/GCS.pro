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
    src/comnet/src/message/AirVehicleGroundRelativeState.cpp \
    src/comnet/src/message/CommunicationsPayloadCommand.cpp \
    src/comnet/src/message/CommunicationsPayloadConfigurationCommand.cpp \
    src/comnet/src/message/CommunicationsPayloadStatus.cpp \
    src/comnet/src/message/ConnectionReply.cpp \
    src/comnet/src/message/ConnectionRequest.cpp \
    src/comnet/src/message/Enter.cpp \
    src/comnet/src/message/Exit.cpp \
    src/comnet/src/message/PayloadBayCommand.cpp \
    src/comnet/src/message/PayloadBayModeCommand.cpp \
    src/comnet/src/message/PayloadBayStatus.cpp \
    src/comnet/src/message/PayloadDataRecorderCommand.cpp \
    src/comnet/src/message/PayloadDataRecorderStatus.cpp \
    src/comnet/src/message/PayloadOperatingStatus.cpp \
    src/comnet/src/message/PayloadOperationCommand.cpp \
    src/comnet/src/message/Ping.cpp \
    src/comnet/src/message/Pong.cpp \
    src/comnet/src/message/RawData.cpp \
    src/comnet/src/message/ROVStatusMessage.cpp \
    src/comnet/src/message/TargetAcknowledgement.cpp \
    src/comnet/src/message/TargetStatus.cpp \
    src/comnet/src/message/UAVBattery.cpp \
    src/comnet/src/message/UAVCollisionAvodianceMessage.cpp \
    src/comnet/src/message/UAVCollisionAvodianceStatus.cpp \
    src/comnet/src/message/UAVHeading.cpp \
    src/comnet/src/message/UAVLocation.cpp \
    src/comnet/src/message/UAVMissionStatus.cpp \
    src/comnet/src/message/UAVSpeed.cpp \
    src/comnet/src/message/UUVStatus.cpp \
    src/comnet/src/message/VehicleAttitude.cpp \
    src/comnet/src/message/VehicleAuthorizationReply.cpp \
    src/comnet/src/message/VehicleAuthorizationRequest.cpp \
    src/comnet/src/message/VehicleBodySensedState.cpp \
    src/comnet/src/message/VehicleGlobalPosition.cpp \
    src/comnet/src/message/VehicleIdentification.cpp \
    src/comnet/src/message/VehicleInertialState.cpp \
    src/comnet/src/message/VehicleJoystickCommand.cpp \
    src/comnet/src/message/VehicleModeCommand.cpp \
    src/comnet/src/message/VehicleSystemStatus.cpp \
    src/comnet/src/message/VehicleTelemetryCommand.cpp \
    src/comnet/src/message/VehicleTerminationCommand.cpp \
    src/comnet/src/comnet.cpp \
    src/comnet/src/comnet_marshal.cpp \
    src/comnet/src/comnet_message.cpp \
    src/comnet/src/comnet_parser.cpp \
    src/comnet/src/comnet_protocol.cpp \
    src/comnet/src/cond.cpp \
    src/comnet/src/datalink.cpp \
    src/comnet/src/error_handle.cpp \
    src/comnet/src/mutexCom.cpp \
    src/comnet/src/pqueue.cpp \
    src/comnet/src/rand_array.cpp \
    src/comnet/src/random_numbers.cpp \
    src/comnet/src/serial.cpp \
    src/comnet/src/threadCom.cpp \
    src/comnet/src/udp.cpp \
    src/comnet/src/zigBee.cpp \
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
    src/joystickinput.cpp


HEADERS += \
    src/comnet/include/cryptopp563/3way.h \
    src/comnet/include/cryptopp563/adler32.h \
    src/comnet/include/cryptopp563/aes.h \
    src/comnet/include/cryptopp563/algebra.h \
    src/comnet/include/cryptopp563/algparam.h \
    src/comnet/include/cryptopp563/arc4.h \
    src/comnet/include/cryptopp563/argnames.h \
    src/comnet/include/cryptopp563/asn.h \
    src/comnet/include/cryptopp563/authenc.h \
    src/comnet/include/cryptopp563/base32.h \
    src/comnet/include/cryptopp563/base64.h \
    src/comnet/include/cryptopp563/basecode.h \
    src/comnet/include/cryptopp563/bench.h \
    src/comnet/include/cryptopp563/blowfish.h \
    src/comnet/include/cryptopp563/blumshub.h \
    src/comnet/include/cryptopp563/camellia.h \
    src/comnet/include/cryptopp563/cast.h \
    src/comnet/include/cryptopp563/cbcmac.h \
    src/comnet/include/cryptopp563/ccm.h \
    src/comnet/include/cryptopp563/channels.h \
    src/comnet/include/cryptopp563/cmac.h \
    src/comnet/include/cryptopp563/config.h \
    src/comnet/include/cryptopp563/cpu.h \
    src/comnet/include/cryptopp563/crc.h \
    src/comnet/include/cryptopp563/cryptlib.h \
    src/comnet/include/cryptopp563/default.h \
    src/comnet/include/cryptopp563/des.h \
    src/comnet/include/cryptopp563/dh.h \
    src/comnet/include/cryptopp563/dh2.h \
    src/comnet/include/cryptopp563/dll.h \
    src/comnet/include/cryptopp563/dmac.h \
    src/comnet/include/cryptopp563/dsa.h \
    src/comnet/include/cryptopp563/eax.h \
    src/comnet/include/cryptopp563/ec2n.h \
    src/comnet/include/cryptopp563/eccrypto.h \
    src/comnet/include/cryptopp563/ecp.h \
    src/comnet/include/cryptopp563/elgamal.h \
    src/comnet/include/cryptopp563/emsa2.h \
    src/comnet/include/cryptopp563/eprecomp.h \
    src/comnet/include/cryptopp563/esign.h \
    src/comnet/include/cryptopp563/factory.h \
    src/comnet/include/cryptopp563/files.h \
    src/comnet/include/cryptopp563/filters.h \
    src/comnet/include/cryptopp563/fips140.h \
    src/comnet/include/cryptopp563/fltrimpl.h \
    src/comnet/include/cryptopp563/gcm.h \
    src/comnet/include/cryptopp563/gf256.h \
    src/comnet/include/cryptopp563/gf2_32.h \
    src/comnet/include/cryptopp563/gf2n.h \
    src/comnet/include/cryptopp563/gfpcrypt.h \
    src/comnet/include/cryptopp563/gost.h \
    src/comnet/include/cryptopp563/gzip.h \
    src/comnet/include/cryptopp563/hex.h \
    src/comnet/include/cryptopp563/hkdf.h \
    src/comnet/include/cryptopp563/hmac.h \
    src/comnet/include/cryptopp563/hrtimer.h \
    src/comnet/include/cryptopp563/ida.h \
    src/comnet/include/cryptopp563/idea.h \
    src/comnet/include/cryptopp563/integer.h \
    src/comnet/include/cryptopp563/iterhash.h \
    src/comnet/include/cryptopp563/lubyrack.h \
    src/comnet/include/cryptopp563/luc.h \
    src/comnet/include/cryptopp563/mars.h \
    src/comnet/include/cryptopp563/md2.h \
    src/comnet/include/cryptopp563/md4.h \
    src/comnet/include/cryptopp563/md5.h \
    src/comnet/include/cryptopp563/mdc.h \
    src/comnet/include/cryptopp563/mersenne.h \
    src/comnet/include/cryptopp563/misc.h \
    src/comnet/include/cryptopp563/modarith.h \
    src/comnet/include/cryptopp563/modes.h \
    src/comnet/include/cryptopp563/modexppc.h \
    src/comnet/include/cryptopp563/mqueue.h \
    src/comnet/include/cryptopp563/mqv.h \
    src/comnet/include/cryptopp563/nbtheory.h \
    src/comnet/include/cryptopp563/network.h \
    src/comnet/include/cryptopp563/nr.h \
    src/comnet/include/cryptopp563/oaep.h \
    src/comnet/include/cryptopp563/oids.h \
    src/comnet/include/cryptopp563/osrng.h \
    src/comnet/include/cryptopp563/panama.h \
    src/comnet/include/cryptopp563/pch.h \
    src/comnet/include/cryptopp563/pkcspad.h \
    src/comnet/include/cryptopp563/polynomi.h \
    src/comnet/include/cryptopp563/pssr.h \
    src/comnet/include/cryptopp563/pubkey.h \
    src/comnet/include/cryptopp563/pwdbased.h \
    src/comnet/include/cryptopp563/queue.h \
    src/comnet/include/cryptopp563/rabin.h \
    src/comnet/include/cryptopp563/randpool.h \
    src/comnet/include/cryptopp563/rc2.h \
    src/comnet/include/cryptopp563/rc5.h \
    src/comnet/include/cryptopp563/rc6.h \
    src/comnet/include/cryptopp563/rdrand.h \
    src/comnet/include/cryptopp563/resource.h \
    src/comnet/include/cryptopp563/rijndael.h \
    src/comnet/include/cryptopp563/ripemd.h \
    src/comnet/include/cryptopp563/rng.h \
    src/comnet/include/cryptopp563/rsa.h \
    src/comnet/include/cryptopp563/rw.h \
    src/comnet/include/cryptopp563/safer.h \
    src/comnet/include/cryptopp563/salsa.h \
    src/comnet/include/cryptopp563/seal.h \
    src/comnet/include/cryptopp563/secblock.h \
    src/comnet/include/cryptopp563/seckey.h \
    src/comnet/include/cryptopp563/seed.h \
    src/comnet/include/cryptopp563/serpent.h \
    src/comnet/include/cryptopp563/serpentp.h \
    src/comnet/include/cryptopp563/sha.h \
    src/comnet/include/cryptopp563/sha3.h \
    src/comnet/include/cryptopp563/shacal2.h \
    src/comnet/include/cryptopp563/shark.h \
    src/comnet/include/cryptopp563/simple.h \
    src/comnet/include/cryptopp563/skipjack.h \
    src/comnet/include/cryptopp563/smartptr.h \
    src/comnet/include/cryptopp563/socketft.h \
    src/comnet/include/cryptopp563/sosemanuk.h \
    src/comnet/include/cryptopp563/square.h \
    src/comnet/include/cryptopp563/stdcpp.h \
    src/comnet/include/cryptopp563/strciphr.h \
    src/comnet/include/cryptopp563/tea.h \
    src/comnet/include/cryptopp563/tiger.h \
    src/comnet/include/cryptopp563/trdlocal.h \
    src/comnet/include/cryptopp563/trunhash.h \
    src/comnet/include/cryptopp563/ttmac.h \
    src/comnet/include/cryptopp563/twofish.h \
    src/comnet/include/cryptopp563/validate.h \
    src/comnet/include/cryptopp563/vmac.h \
    src/comnet/include/cryptopp563/wait.h \
    src/comnet/include/cryptopp563/wake.h \
    src/comnet/include/cryptopp563/whrlpool.h \
    src/comnet/include/cryptopp563/winpipes.h \
    src/comnet/include/cryptopp563/words.h \
    src/comnet/include/cryptopp563/xtr.h \
    src/comnet/include/cryptopp563/xtrcrypt.h \
    src/comnet/include/cryptopp563/zdeflate.h \
    src/comnet/include/cryptopp563/zinflate.h \
    src/comnet/include/cryptopp563/zlib.h \
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
    src/comnet/include/message/AirVehicleGroundRelativeState.h \
    src/comnet/include/message/CommunicationsPayloadCommand.h \
    src/comnet/include/message/CommunicationsPayloadConfigurationCommand.h \
    src/comnet/include/message/CommunicationsPayloadStatus.h \
    src/comnet/include/message/ConnectionReply.h \
    src/comnet/include/message/ConnectionRequest.h \
    src/comnet/include/message/Enter.h \
    src/comnet/include/message/Exit.h \
    src/comnet/include/message/PayloadBayCommand.h \
    src/comnet/include/message/PayloadBayModeCommand.h \
    src/comnet/include/message/PayloadBayStatus.h \
    src/comnet/include/message/PayloadDataRecorderCommand.h \
    src/comnet/include/message/PayloadDataRecorderStatus.h \
    src/comnet/include/message/PayloadOperatingStatus.h \
    src/comnet/include/message/PayloadOperationCommand.h \
    src/comnet/include/message/Ping.h \
    src/comnet/include/message/Pong.h \
    src/comnet/include/message/RawData.h \
    src/comnet/include/message/ROVStatusMessage.h \
    src/comnet/include/message/TargetAcknowledgement.h \
    src/comnet/include/message/TargetStatus.h \
    src/comnet/include/message/UAVBattery.h \
    src/comnet/include/message/UAVCollisionAvodianceMessage.h \
    src/comnet/include/message/UAVCollisionAvodianceStatus.h \
    src/comnet/include/message/UAVHeading.h \
    src/comnet/include/message/UAVLocation.h \
    src/comnet/include/message/UAVMissionStatus.h \
    src/comnet/include/message/UAVSpeed.h \
    src/comnet/include/message/UUVStatus.h \
    src/comnet/include/message/VehicleAttitude.h \
    src/comnet/include/message/VehicleAuthorizationReply.h \
    src/comnet/include/message/VehicleAuthorizationRequest.h \
    src/comnet/include/message/VehicleBodySensedState.h \
    src/comnet/include/message/VehicleGlobalPosition.h \
    src/comnet/include/message/VehicleIdentification.h \
    src/comnet/include/message/VehicleInertialState.h \
    src/comnet/include/message/VehicleJoystickCommand.h \
    src/comnet/include/message/VehicleModeCommand.h \
    src/comnet/include/message/VehicleSystemStatus.h \
    src/comnet/include/message/VehicleTelemetryCommand.h \
    src/comnet/include/message/VehicleTerminationCommand.h \
    src/comnet/include/comnet.h \
    src/comnet/include/comnet_marshal.h \
    src/comnet/include/comnet_message.h \
    src/comnet/include/comnet_parser.h \
    src/comnet/include/comnet_protocol.h \
    src/comnet/include/cond.h \
    src/comnet/include/config.h \
    src/comnet/include/datalink.h \
    src/comnet/include/error_handle.h \
    src/comnet/include/mutexCom.h \
    src/comnet/include/pqueue.h \
    src/comnet/include/priority_queue.h \
    src/comnet/include/random_numbers.h \
    src/comnet/include/serial.h \
    src/comnet/include/standard_logic.h \
    src/comnet/include/threadCom.h \
    src/comnet/include/udp.h \
    src/comnet/include/zigBee.h \
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
    src/joystickinput.h


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

INCLUDEPATH += $$PWD/src/comnet/include/cryptopp563
DEPENDPATH += $$PWD/src/comnet/include/cryptopp563
INCLUDEPATH += $$PWD/src/comnet/include/libxbee3-3.0.11
DEPENDPATH += $$PWD/src/comnet/include/libxbee3-3.0.11
INCLUDEPATH += $$PWD/src/comnet/include
DEPENDPATH += $$PWD/src/comnet/include
INCLUDEPATH += $$PWD/src/comnet/
DEPENDPATH += $$PWD/src/comnet/
INCLUDEPATH += $$PWD/src/
DEPENDPATH += $$PWD/src/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/comnet/release/ -lNGCP_COM
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/comnet/debug/ -lNGCP_COM
else:unix: LIBS += -L$$PWD/src/comnet/ -lNGCP_COM

INCLUDEPATH += $$PWD/src/comnet
DEPENDPATH += $$PWD/src/comnet

unix|win32: LIBS += -L$$PWD/src/comnet/ -llibxbee3

INCLUDEPATH += $$PWD/src/comnet
DEPENDPATH += $$PWD/src/comnet

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/comnet/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/comnet/ -lcryptlibd
else:unix: LIBS += -L$$PWD/src/comnet/ -lcryptlib

INCLUDEPATH += $$PWD/src/comnet
DEPENDPATH += $$PWD/src/comnet
