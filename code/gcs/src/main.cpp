
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

#include <CommProto/commproto.h>
#include <Packets.hpp>

//Our headers
#include "mainwindow.h"
#include "rx_thread.h"
//-------------TEST PACKET----------------------
//GCS IS ID 1

using namespace ngcp;
// Callback function that we will be using to link to Ping packet.
extern error_t VehicleAuthorizationRequestCallback(
  const comnet::Header &header, VehicleAuthorizationRequest &packet, comnet::Comms &node);


int main(int argc, char *argv[])
{

   std::condition_variable cond;

    // GCSNode 1
    comnet::Comms gcs1(1);
    // GCSNode
    comnet::Comms gcs2(2);

    //Used for encryption
    std::cout << std::boolalpha << gcs1.LoadKey("NGCP project 2016");
    std::cout << std::boolalpha << gcs1.LoadKey("NGCP project 2016");

    comnet::architecture::os::CommMutex mut;
    comnet::architecture::os::CommLock commlock(mut);

    // This will cause the thread to wait for a few milliseconds, causing any other thread to wait.
    comnet::architecture::os::WaitForMilliseconds(commlock, cond, 1000);

    // ComNode 1 init and add Connection.
    std::cout << "Init connection succeeded: "
        << std::boolalpha
        << gcs2.InitConnection(UDP_LINK, "1338", "127.0.0.1")
        << std::endl;
    std::cout << "Connected to address: "
        << std::boolalpha
        << gcs2.AddAddress(1, "127.0.0.1", 1337)
        << std::endl;
  // CommNode 2 init and add Connection.
    std::cout << "Init connection succeeded: "
        << std::boolalpha
        << gcs1.InitConnection(UDP_LINK, "1337", "127.0.0.1")
        //For XBEE
       // << gcs1.InitConnection( ZIGBEE_LINK, "COM4","",57600)
        << std::endl;
    std::cout << "Connected to address: "
        << std::boolalpha
        << gcs1.AddAddress(2, "127.0.0.1", 1338)
        //For XBEE
        //<< gcs1.AddAddress(5, "0013A20040917A31")
        << std::endl;

    // CommNode Callback linking.
    gcs1.LinkCallback(new VehicleAuthorizationRequest(),
        new comnet::Callback((comnet::callback_t) VehicleAuthorizationRequestCallback));
    gcs2.LinkCallback(new VehicleAuthorizationRequest(),
        new comnet::Callback((comnet::callback_t) VehicleAuthorizationRequestCallback));


    // Allow client to suppress or unsuppress messages handled by the CommProtocol Library.
    comnet::debug::Log::Suppress(comnet::debug::LOG_NOTIFY);
    comnet::debug::Log::Suppress(comnet::debug::LOG_WARNING);
    comnet::debug::Log::Suppress(comnet::debug::LOG_NOTE);

    // Test packet.
    VehicleAuthorizationRequest request(1,2,3,4);
    // NOTE(All): Be sure to run the nodes! If not, the threads won't execute!
    gcs1.Run();
    gcs2.Run();

    // Loop. To exit, Click the red button on the top left (Windows Visual Studio) OR
    // CNTRL+C (Linux).

   // while (true) {
        std::cout << "Sending..." << std::endl;

        //comm1 will be sending the packet.
        //Change 2 to 5 for XBEE
        gcs1.Send(request, 2);

        //std::cout << "Test..." << std::endl;
       std::this_thread::sleep_for(std::chrono::milliseconds(1000));
         //std::cout << "SleepWorking..." << std::endl;

    //}
      std::cout << "Ending..." << std::endl;
  //  std::cin.ignore();
#ifdef Q_OS_WIN
    // Force usage of OpenGL ES through ANGLE on Windows
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
#endif

    QApplication application(argc, argv);
    
    MainWindow mw;
    application.connect(mw.quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    return application.exec();
}

