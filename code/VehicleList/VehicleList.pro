#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T14:17:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VehicleList
TEMPLATE = app


SOURCES += main.cpp\
        vehiclelistgui.cpp \
    vehicleelementdisplay.cpp \
    ../gcs/src/Vehicle22.cpp \
    Vehicle22.cpp \
    Waypoint22.cpp

HEADERS  += vehiclelistgui.h \
    vehicleelementdisplay.h \
    ../gcs/src/Vehicle22.h \
    Vehicle22.h \
    Waypoint22.h
