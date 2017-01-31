#-------------------------------------------------
#
# Project created by QtCreator 2014-02-22T00:09:37
#
#-------------------------------------------------

QT       += testlib widgets

TARGET = tst_toolbartest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_toolbartest.cpp \
    ../../gcs_toolbar.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    ../../gcs_toolbar.qrc

FORMS += \
    ../../gcs_toolbar.ui

HEADERS += \
    ../../gcs_toolbar.h
