#-------------------------------------------------
#
# Project created by QtCreator 2013-09-24T17:03:18
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qfi_example
TEMPLATE = app

#-------------------------------------------------

win32: DEFINES += WIN32 _WINDOWS _USE_MATH_DEFINES

win32:CONFIG(release, debug|release):    DEFINES += NDEBUG
else:win32:CONFIG(debug, debug|release): DEFINES += _DEBUG

#-------------------------------------------------

INCLUDEPATH += ./ ./example

#-------------------------------------------------

HEADERS += \
    example/LayoutSquare.h \
    example/MainWindow.h \
    example/WidgetADI.h \
    example/WidgetPFD.h \
    qfi_ADI.h \
    qfi_PFD.h \
    example/WidgetSix.h

SOURCES += \
    example/LayoutSquare.cpp \
    example/main.cpp \
    example/MainWindow.cpp \
    example/WidgetADI.cpp \
    example/WidgetPFD.cpp \
    qfi_ADI.cpp \
    qfi_PFD.cpp \
    example/WidgetSix.cpp

FORMS += \
    example/MainWindow.ui \
    example/WidgetADI.ui \
    example/WidgetALT.ui \
    example/WidgetASI.ui \
    example/WidgetHSI.ui \
    example/WidgetPFD.ui \
    example/WidgetTC.ui \
    example/WidgetVSI.ui \
    example/WidgetSix.ui

RESOURCES += \
    qfi.qrc
