#-------------------------------------------------
#
# Project created by QtCreator 2014-02-11T01:22:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GcsToolbar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gcs_toolbar.cpp

HEADERS  += mainwindow.h \
    gcs_toolbar.h

FORMS    += mainwindow.ui \
    gcs_toolbar.ui

RESOURCES += \
    gcs_toolbar.qrc

QMAKE_INFO_PLIST = /Users/calvinh/Qt5.2.0/Info.plist.app

OTHER_FILES += \
    gcstoolbar.qss
