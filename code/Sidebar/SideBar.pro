#-------------------------------------------------
#
# Project created by QtCreator 2014-02-01T16:50:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SideBar
TEMPLATE = app


SOURCES += main.cpp\
        src/sidebar.cpp \
        src/togglebutton.cpp \

HEADERS  += include/sidebar.h \
           include/togglebutton.h \
           include/main.h

RESOURCES += \
    src/icons.qrc

