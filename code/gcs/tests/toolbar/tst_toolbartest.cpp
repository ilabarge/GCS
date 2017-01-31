#include <QString>
//#include <QtTest>
#include <QCoreApplication>
#include "../../gcs_toolbar.h"

class ToolbarTest : public QObject
{
    Q_OBJECT

public:
    ToolbarTest();

private:
    GcsToolbar* mtb;

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testMapView();
    void testUavView();
    void testUgvView();
    void testPayload();
    void testWaypoints();
    void testZoning();
    void testSettings();
};

ToolbarTest::ToolbarTest()
{
}

void ToolbarTest::initTestCase()
{
    mtb = new GcsToolbar;
}

void ToolbarTest::cleanupTestCase()
{
    delete mtb;
}

void ToolbarTest::testMapView()
{
    QAction *actMapView = mtb->getActionMapView();
    QSignalSpy spy(mtb, SIGNAL(clickedMapView()));
    actMapView->trigger();
    QVERIFY2(spy.count() == 1, "No clickedMapView() signal.");
}

void ToolbarTest::testUavView()
{
    GcsToolbar::Vehicle sig;
    QAction *actUavCpp = mtb->getVehicleAction(GcsToolbar::UAV_CPP);
    QAction *actUavCpp2 = mtb->getVehicleAction(GcsToolbar::UAV_CPP2);
    QAction *actUavSlo = mtb->getVehicleAction(GcsToolbar::UAV_SLO);
    QSignalSpy spy(mtb, SIGNAL(clickedUavView(GcsToolbar::Vehicle)));

    actUavCpp->trigger();
    if (spy.length() < 1) {
        QFAIL("No clickedUavView() emitted.");
    } else {
        sig = qvariant_cast<GcsToolbar::Vehicle>(spy.at(0).at(0));
        bool signalIsUavCpp = sig == GcsToolbar::UAV_CPP;
        QVERIFY2(signalIsUavCpp, "Not clickedUavView(UAV_CPP)");
    }
    actUavCpp2->trigger();
    if (spy.length() < 2) {
        QFAIL("No 2nd clickedUavView() emitted.");
    } else {
        sig = qvariant_cast<GcsToolbar::Vehicle>(spy.at(1).at(0));
        bool signalIsUavCpp2 = sig == GcsToolbar::UAV_CPP2;
        QVERIFY2(signalIsUavCpp2, "Not clickedUavView(UAV_CPP2)");
    }
    actUavSlo->trigger();
    if (spy.length() < 3) {
        QFAIL("No 3rd clickedUavView() emitted.");
    } else {
        sig = qvariant_cast<GcsToolbar::Vehicle>(spy.at(2).at(0));
        bool signalIsUavSlo = sig == GcsToolbar::UAV_SLO;
        QVERIFY2(signalIsUavSlo, "Not clickedUavView(UAV_SLO)");
    }
    QVERIFY2(spy.length() == 3, "More than 3 signals");
}

void ToolbarTest::testUgvView()
{
    GcsToolbar::Vehicle sig;
    QAction *actUgvCpp = mtb->getVehicleAction(GcsToolbar::UGV_CPP);
    QAction *actUgvSlo = mtb->getVehicleAction(GcsToolbar::UGV_SLO);
    QSignalSpy spy(mtb, SIGNAL(clickedUgvView(GcsToolbar::Vehicle)));

    actUgvCpp->trigger();
    if (spy.length() < 1) {
        QFAIL("No clickedUavView() emitted.");
    } else {
        sig = qvariant_cast<GcsToolbar::Vehicle>(spy.at(0).at(0));
        bool signalIsUgvCpp = sig == GcsToolbar::UGV_CPP;
        QVERIFY2(signalIsUgvCpp, "Not clickedUgvView(UGV_CPP)");
    }
    actUgvSlo->trigger();
    if (spy.length() < 2) {
        QFAIL("No 2nd clickedUgvView() emitted.");
    } else {
        sig = qvariant_cast<GcsToolbar::Vehicle>(spy.at(1).at(0));
        bool signalIsUgvSlo = sig == GcsToolbar::UGV_SLO;
        QVERIFY2(signalIsUgvSlo, "Not clickedUgvView(UAV_SLO)");
    }
    QVERIFY2(spy.length() == 2, "More than 2 signals");
}

void ToolbarTest::testPayload()
{
    QAction *act = mtb->getActionPayload();
    QSignalSpy spy(mtb, SIGNAL(clickedPayload()));
    act->trigger();
    QVERIFY2(spy.count() == 1, "No clickedPayload() signal.");
}

void ToolbarTest::testWaypoints()
{
    QAction *act = mtb->getActionWaypoints();
    QSignalSpy spy(mtb, SIGNAL(clickedWaypoints()));
    act->trigger();
    QVERIFY2(spy.count() == 1, "No clickedWaypoints() signal.");
}

void ToolbarTest::testZoning()
{
    QAction *act = mtb->getActionZoning();
    QSignalSpy spy(mtb, SIGNAL(clickedZoning()));
    act->trigger();
    QVERIFY2(spy.count() == 1, "No clickedZoning() signal.");
}

void ToolbarTest::testSettings()
{
    QAction *act = mtb->getActionSettings();
    QSignalSpy spy(mtb, SIGNAL(clickedSettings()));
    act->trigger();
    QVERIFY2(spy.count() == 1, "No clickedSettings() signal.");
}
QTEST_MAIN(ToolbarTest)
