#include <QTest>
#include <QByteArray>
#include "validate_data.h"

class TestIt : public QObject {
    Q_OBJECT

private slots:
    void testNothingOkay();         //wrong msg id, wrong length, wrong data
    void testDataOkay();            //wrong msg id, wrong length, right data
    void testLengthOkay();          //wrong msg id, right length, wrong data
    void testDataLengthOkay();      //wrong msg id, right length, right data
    void testMessageOkay();         //right msg id, wrong length, wrong data
    void testMessageDataOkay();     //right msg id, wrong length, right data
    void testMessageLengthOkay();   //right msg id, right length, wrong data
    void testAllOkay();             //right msg id, right length, right data
};

void TestIt::testNothingOkay() {
    quint16 msg = 2001;
    QByteArray data = QByteArray(15, 'l');
    QVERIFY((int) ValidateData::validateData(msg, data) == 2);
}

void TestIt::testDataOkay() {
    quint16 msg = 2001;
    QByteArray data = QByteArray(15, 'l');
    char * d = data.data();
    for (int n = 0; n < 14; n++) {
        *d = 1;
        d++;
    }
    QVERIFY((int) ValidateData::validateData(msg, data) == 2);
}

void TestIt::testLengthOkay() {
    quint16 msg = 2001;
    QByteArray data = QByteArray(14, 'l');
    QVERIFY((int) ValidateData::validateData(msg, data) == 2);
}
void TestIt::testDataLengthOkay() {
    quint16 msg = 2001;
    QByteArray data = QByteArray(14, 'l');
    char * d = data.data();
    d += 13;
    *d = 1;
    QVERIFY((int) ValidateData::validateData(msg, data) == 2);
}

void TestIt::testMessageOkay() {
    quint16 msg = 2000;
    QByteArray data = QByteArray(15, 'l');
    QVERIFY((int) ValidateData::validateData(msg, data) == 1);
}

void TestIt::testMessageDataOkay() {
    quint16 msg = 2000;
    QByteArray data = QByteArray(15, 'l');
    char * d = data.data();
    for (int n = 0; n < 14; n++) {
        *d = 1;
        d++;
    }
    QVERIFY((int) ValidateData::validateData(msg, data) == 1);
}

void TestIt::testMessageLengthOkay() {
    quint16 msg = 2000;
    QByteArray data = QByteArray(14, 'l');
    QVERIFY((int) ValidateData::validateData(msg, data) == 1);
}

void TestIt::testAllOkay() {
    quint16 msg = 2000;
    QByteArray data = QByteArray(14, 'l');
    char * d = data.data();
    d += 13;
    *d = 1;
    QVERIFY((int) ValidateData::validateData(msg, data) == 0);
}

QTEST_MAIN(TestIt)
#include "testIt.moc"


