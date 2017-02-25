
// Copyright 2013 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

//Qt Headers
#include <QApplication>

//Our headers
#include "mainwindow.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
    // Force usage of OpenGL ES through ANGLE on Windows
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
#endif

    QApplication application(argc, argv);
    
    MainWindow mw;
    application.connect(mw.quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    return application.exec();
}

