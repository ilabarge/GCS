QT       += testlib

QT       -= gui

CONFIG   += console
CONFIG   += testcase
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += validateData.cpp \
    testIt.cpp

HEADERS += \
    validate_data.h
