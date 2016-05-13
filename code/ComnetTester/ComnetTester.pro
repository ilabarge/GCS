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
    comnet/src/message/Enter.cpp \
    comnet/src/message/Exit.cpp \
    comnet/src/message/PayloadBayCommand.cpp \
    comnet/src/message/PayloadBayModeCommand.cpp \
    comnet/src/message/Ping.cpp \
    comnet/src/message/Pong.cpp \
    comnet/src/message/VehicleAttitude.cpp \
    comnet/src/message/VehicleAuthorizationReply.cpp \
    comnet/src/message/VehicleAuthorizationRequest.cpp \
    comnet/src/message/VehicleBodySensedState.cpp \
    comnet/src/message/VehicleGlobalPosition.cpp \
    comnet/src/message/VehicleIdentification.cpp \
    comnet/src/message/VehicleInertialState.cpp \
    comnet/src/message/VehicleModeCommand.cpp \
    comnet/src/message/VehicleSystemStatus.cpp \
    comnet/src/message/VehicleTelemetryCommand.cpp \
    comnet/src/message/VehicleTerminationCommand.cpp \
    comnet/src/comnet.cpp \
    comnet/src/comnet_marshal.cpp \
    comnet/src/comnet_message.cpp \
    comnet/src/comnet_parser.cpp \
    comnet/src/comnet_protocol.cpp \
    comnet/src/cond.cpp \
    comnet/src/datalink.cpp \
    comnet/src/mutexCom.cpp \
    comnet/src/pqueue.cpp \
    comnet/src/rand_array.cpp \
    comnet/src/random_numbers.cpp \
    comnet/src/serial.cpp \
    comnet/src/threadCom.cpp \
    comnet/src/udp.cpp \
    comnet/src/zigBee.cpp \
    comnet/src/error_handle.cpp

HEADERS  += mainwindow.h \
    networking.h \
    rx_thread.h \
    comnet/include/cryptopp563/3way.h \
    comnet/include/cryptopp563/adler32.h \
    comnet/include/cryptopp563/aes.h \
    comnet/include/cryptopp563/algebra.h \
    comnet/include/cryptopp563/algparam.h \
    comnet/include/cryptopp563/arc4.h \
    comnet/include/cryptopp563/argnames.h \
    comnet/include/cryptopp563/asn.h \
    comnet/include/cryptopp563/authenc.h \
    comnet/include/cryptopp563/base32.h \
    comnet/include/cryptopp563/base64.h \
    comnet/include/cryptopp563/basecode.h \
    comnet/include/cryptopp563/bench.h \
    comnet/include/cryptopp563/blowfish.h \
    comnet/include/cryptopp563/blumshub.h \
    comnet/include/cryptopp563/camellia.h \
    comnet/include/cryptopp563/cast.h \
    comnet/include/cryptopp563/cbcmac.h \
    comnet/include/cryptopp563/ccm.h \
    comnet/include/cryptopp563/channels.h \
    comnet/include/cryptopp563/cmac.h \
    comnet/include/cryptopp563/config.h \
    comnet/include/cryptopp563/cpu.h \
    comnet/include/cryptopp563/crc.h \
    comnet/include/cryptopp563/cryptlib.h \
    comnet/include/cryptopp563/default.h \
    comnet/include/cryptopp563/des.h \
    comnet/include/cryptopp563/dh.h \
    comnet/include/cryptopp563/dh2.h \
    comnet/include/cryptopp563/dll.h \
    comnet/include/cryptopp563/dmac.h \
    comnet/include/cryptopp563/dsa.h \
    comnet/include/cryptopp563/eax.h \
    comnet/include/cryptopp563/ec2n.h \
    comnet/include/cryptopp563/eccrypto.h \
    comnet/include/cryptopp563/ecp.h \
    comnet/include/cryptopp563/elgamal.h \
    comnet/include/cryptopp563/emsa2.h \
    comnet/include/cryptopp563/eprecomp.h \
    comnet/include/cryptopp563/esign.h \
    comnet/include/cryptopp563/factory.h \
    comnet/include/cryptopp563/files.h \
    comnet/include/cryptopp563/filters.h \
    comnet/include/cryptopp563/fips140.h \
    comnet/include/cryptopp563/fltrimpl.h \
    comnet/include/cryptopp563/gcm.h \
    comnet/include/cryptopp563/gf256.h \
    comnet/include/cryptopp563/gf2_32.h \
    comnet/include/cryptopp563/gf2n.h \
    comnet/include/cryptopp563/gfpcrypt.h \
    comnet/include/cryptopp563/gost.h \
    comnet/include/cryptopp563/gzip.h \
    comnet/include/cryptopp563/hex.h \
    comnet/include/cryptopp563/hkdf.h \
    comnet/include/cryptopp563/hmac.h \
    comnet/include/cryptopp563/hrtimer.h \
    comnet/include/cryptopp563/ida.h \
    comnet/include/cryptopp563/idea.h \
    comnet/include/cryptopp563/integer.h \
    comnet/include/cryptopp563/iterhash.h \
    comnet/include/cryptopp563/lubyrack.h \
    comnet/include/cryptopp563/luc.h \
    comnet/include/cryptopp563/mars.h \
    comnet/include/cryptopp563/md2.h \
    comnet/include/cryptopp563/md4.h \
    comnet/include/cryptopp563/md5.h \
    comnet/include/cryptopp563/mdc.h \
    comnet/include/cryptopp563/mersenne.h \
    comnet/include/cryptopp563/misc.h \
    comnet/include/cryptopp563/modarith.h \
    comnet/include/cryptopp563/modes.h \
    comnet/include/cryptopp563/modexppc.h \
    comnet/include/cryptopp563/mqueue.h \
    comnet/include/cryptopp563/mqv.h \
    comnet/include/cryptopp563/nbtheory.h \
    comnet/include/cryptopp563/network.h \
    comnet/include/cryptopp563/nr.h \
    comnet/include/cryptopp563/oaep.h \
    comnet/include/cryptopp563/oids.h \
    comnet/include/cryptopp563/osrng.h \
    comnet/include/cryptopp563/panama.h \
    comnet/include/cryptopp563/pch.h \
    comnet/include/cryptopp563/pkcspad.h \
    comnet/include/cryptopp563/polynomi.h \
    comnet/include/cryptopp563/pssr.h \
    comnet/include/cryptopp563/pubkey.h \
    comnet/include/cryptopp563/pwdbased.h \
    comnet/include/cryptopp563/queue.h \
    comnet/include/cryptopp563/rabin.h \
    comnet/include/cryptopp563/randpool.h \
    comnet/include/cryptopp563/rc2.h \
    comnet/include/cryptopp563/rc5.h \
    comnet/include/cryptopp563/rc6.h \
    comnet/include/cryptopp563/rdrand.h \
    comnet/include/cryptopp563/resource.h \
    comnet/include/cryptopp563/rijndael.h \
    comnet/include/cryptopp563/ripemd.h \
    comnet/include/cryptopp563/rng.h \
    comnet/include/cryptopp563/rsa.h \
    comnet/include/cryptopp563/rw.h \
    comnet/include/cryptopp563/safer.h \
    comnet/include/cryptopp563/salsa.h \
    comnet/include/cryptopp563/seal.h \
    comnet/include/cryptopp563/secblock.h \
    comnet/include/cryptopp563/seckey.h \
    comnet/include/cryptopp563/seed.h \
    comnet/include/cryptopp563/serpent.h \
    comnet/include/cryptopp563/serpentp.h \
    comnet/include/cryptopp563/sha.h \
    comnet/include/cryptopp563/sha3.h \
    comnet/include/cryptopp563/shacal2.h \
    comnet/include/cryptopp563/shark.h \
    comnet/include/cryptopp563/simple.h \
    comnet/include/cryptopp563/skipjack.h \
    comnet/include/cryptopp563/smartptr.h \
    comnet/include/cryptopp563/socketft.h \
    comnet/include/cryptopp563/sosemanuk.h \
    comnet/include/cryptopp563/square.h \
    comnet/include/cryptopp563/stdcpp.h \
    comnet/include/cryptopp563/strciphr.h \
    comnet/include/cryptopp563/tea.h \
    comnet/include/cryptopp563/tiger.h \
    comnet/include/cryptopp563/trdlocal.h \
    comnet/include/cryptopp563/trunhash.h \
    comnet/include/cryptopp563/ttmac.h \
    comnet/include/cryptopp563/twofish.h \
    comnet/include/cryptopp563/validate.h \
    comnet/include/cryptopp563/vmac.h \
    comnet/include/cryptopp563/wait.h \
    comnet/include/cryptopp563/wake.h \
    comnet/include/cryptopp563/whrlpool.h \
    comnet/include/cryptopp563/winpipes.h \
    comnet/include/cryptopp563/words.h \
    comnet/include/cryptopp563/xtr.h \
    comnet/include/cryptopp563/xtrcrypt.h \
    comnet/include/cryptopp563/zdeflate.h \
    comnet/include/cryptopp563/zinflate.h \
    comnet/include/cryptopp563/zlib.h \
    comnet/include/libxbee3-3.0.11/conn.h \
    comnet/include/libxbee3-3.0.11/frame.h \
    comnet/include/libxbee3-3.0.11/internal.h \
    comnet/include/libxbee3-3.0.11/ll.h \
    comnet/include/libxbee3-3.0.11/log.h \
    comnet/include/libxbee3-3.0.11/mode.h \
    comnet/include/libxbee3-3.0.11/mutex.h \
    comnet/include/libxbee3-3.0.11/net.h \
    comnet/include/libxbee3-3.0.11/net_callbacks.h \
    comnet/include/libxbee3-3.0.11/net_handlers.h \
    comnet/include/libxbee3-3.0.11/net_io.h \
    comnet/include/libxbee3-3.0.11/pkt.h \
    comnet/include/libxbee3-3.0.11/prepare.h \
    comnet/include/libxbee3-3.0.11/rx.h \
    comnet/include/libxbee3-3.0.11/thread.h \
    comnet/include/libxbee3-3.0.11/tx.h \
    comnet/include/libxbee3-3.0.11/xbee.h \
    comnet/include/libxbee3-3.0.11/xbee_int.h \
    comnet/include/libxbee3-3.0.11/xbeep.h \
    comnet/include/libxbee3-3.0.11/xsys.h \
    comnet/include/libxbee3-3.0.11/xsys_darwin.h \
    comnet/include/libxbee3-3.0.11/xsys_linux.h \
    comnet/include/libxbee3-3.0.11/xsys_win32.h \
    comnet/include/libxbee3-3.0.11/xsys_win32_winpthreads.h \
    comnet/include/message/Enter.h \
    comnet/include/message/Exit.h \
    comnet/include/message/PayloadBayCommand.h \
    comnet/include/message/PayloadBayModeCommand.h \
    comnet/include/message/Ping.h \
    comnet/include/message/Pong.h \
    comnet/include/message/VehicleAttitude.h \
    comnet/include/message/VehicleAuthorizationReply.h \
    comnet/include/message/VehicleAuthorizationRequest.h \
    comnet/include/message/VehicleBodySensedState.h \
    comnet/include/message/VehicleGlobalPosition.h \
    comnet/include/message/VehicleIdentification.h \
    comnet/include/message/VehicleInertialState.h \
    comnet/include/message/VehicleModeCommand.h \
    comnet/include/message/VehicleSystemStatus.h \
    comnet/include/message/VehicleTelemetryCommand.h \
    comnet/include/message/VehicleTerminationCommand.h \
    comnet/include/comnet.h \
    comnet/include/comnet_marshal.h \
    comnet/include/comnet_message.h \
    comnet/include/comnet_parser.h \
    comnet/include/comnet_protocol.h \
    comnet/include/cond.h \
    comnet/include/datalink.h \
    #comnet/include/Joystick.h \
    #comnet/include/joystickinput.h \
    comnet/include/mutex.h \
    comnet/include/mutexCom.h \
    comnet/include/pqueue.h \
    comnet/include/priority_queue.h \
    comnet/include/random_numbers.h \
    comnet/include/serial.h \
    comnet/include/standard_logic.h \
    comnet/include/thread.h \
    comnet/include/threadCom.h \
    comnet/include/udp.h \
    comnet/include/zigBee.h \
    comnet/include/config.h \
    comnet/include/error_handle.h \
    comnet/include/Joystick.h \
    comnet/include/joystickinput.h

#FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/comnet/include/cryptopp563/
DEPENDPATH += $$PWD/comnet/include/cryptopp563/
INCLUDEPATH += $$PWD/comnet/include/libxbee3-3.0.11/
DEPENDPATH += $$PWD/comnet/include/libxbee3-3.0.11/
INCLUDEPATH += $$PWD/comnet/src/message/
DEPENDPATH += $$PWD/comnet/src/message/
INCLUDEPATH += $$PWD/comnet/include/
DEPENDPATH += $$PWD/comnet/include/
INCLUDEPATH += $$PWD/comnet/src/
DEPENDPATH += $$PWD/comnet/src/
INCLUDEPATH += $$PWD/comnet/
DEPENDPATH += $$PWD/comnet/


unix|win32: LIBS += -L$$PWD/../gcs/src/comnet/ -llibxbee3

INCLUDEPATH += $$PWD/../gcs/src/comnet
DEPENDPATH += $$PWD/../gcs/src/comnet

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gcs/src/comnet/release/ -lNGCP_COM
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gcs/src/comnet/debug/ -lNGCP_COM
else:unix: LIBS += -L$$PWD/../gcs/src/comnet/ -lNGCP_COM

INCLUDEPATH += $$PWD/../gcs/src/comnet
DEPENDPATH += $$PWD/../gcs/src/comnet

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/comnet/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/comnet/ -lcryptlibd
else:unix: LIBS += -L$$PWD/comnet/ -lcryptlib

INCLUDEPATH += $$PWD/comnet
DEPENDPATH += $$PWD/comnet
