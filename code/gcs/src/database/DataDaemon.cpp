#include "database/DataDaemon.h"

DataDaemon::DataDaemon(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Attempting to open database";
    db = QSqlDatabase::addDatabase("QSQLITE");                                     // Create the SQLite connection

    QDir gcsDir = QDir::homePath() + QDir::separator() + "GCS" + QDir::separator();     // Variable to GCS directory in home folder

    if(!gcsDir.exists()) {
        gcsDir.mkpath(gcsDir.path());       //Make directory if not exist
    }

    db.setDatabaseName(gcsDir.path() + gcsDir.separator() + "database.db");        // Location of SQLite database (User home folder).  Will later change.
    qDebug() << "Database in: " << gcsDir.path() + gcsDir.separator() + "database.db";

    if(db.open()){      
        qDebug() << "Database opened successfully.";

        if (!db.tables().contains("log")) {                                                                           // Check if database already exists.  If not, populate table "log"
            qDebug() << "Database is not populated.  Populating now...";

            QString queryString = QString("CREATE TABLE IF NOT EXISTS log(updatedon DATETIME, vehid INTEGER, vehtype INTEGER, latitude REAL, longitude REAL, altitude INTEGER, heading REAL, xacc REAL, yacc REAL, rollrate REAL, pitchrate REAL, yawrate REAL, velocity REAL, roll REAL, pitch REAL, yaw REAL, mode INTEGER, state INTEGER, battstatus INTEGER);");
            QSqlQuery query(queryString);
        }
        else {
            qDebug() << "Table pre-existed.  Continuing...";
        }

        db.close();
    }
    else{
        qDebug() << "FATAL ERROR OPENING DATABASE. GRAB THE SCOOBY SNACKS AND ABORT!";
    }
}

void DataDaemon::log(QVector<Vehicle22*> &vehicleStore)
{
    for (int i = 0; i < vehicleStore.size(); i++) {
        if (vehicleStore[i]->getNeedsUpdate()) {
            db.open();
        
            if ( !db.open() ) {                                             // Check if database opened correctly
                qDebug() << db.lastError();
                qFatal( "Failed to connect." );
            }
        
            qDebug() << "Database opened for vehicle in index " << i;        // Log correct opening

            Vehicle22* curr = vehicleStore[i];

            qDebug() << "Current Vehicle: " << curr->getVehicleID();

            QSqlQuery query;
            bool pass = query.exec(QString("INSERT INTO log (updatedon, vehid, vehtype, latitude, longitude, altitude, heading, waypointid, waypointtype, xacc, yacc, rollrate, pitchrate, yawrate, velocity, roll, pitch, yaw, mode, state, battstatus) VALUES(strftime('%s', 'now'), '%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20')").arg(curr->getVehicleID()).arg(curr->getVehicleType()).arg(curr->getLatitude()).arg(curr->getLongitude()).arg(curr->getAltitude()).arg(curr->getHeading()).arg(curr->getXAcceleration()).arg(curr->getYAcceleration()).arg(curr->getRollRate()).arg(curr->getPitchRate()).arg(curr->getYawRate()).arg(curr->getVelocity()).arg(curr->getRoll()).arg(curr->getPitch()).arg(curr->getYaw()).arg(curr->getMode()).arg(curr->getState()).arg(curr->getBatteryStatus()));

            //QSqlQuery query(queryString);              // Cast it!
            //query.prepare(queryString);                 // Prepare it!

            if (!pass) {qDebug() << query.lastError().text();}       // Bop it!
            
            db.close();
        }
    }
}
