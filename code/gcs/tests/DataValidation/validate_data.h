#ifndef VALIDATE_DATA_H
#define VALIDATE_DATA_H

#include <QByteArray>

class ValidateData {
    public:
        static quint8 validateData(quint16 msg, QByteArray data);
        ValidateData();

//    private:
//        ~ValidateData();

    friend class TestIt;
};

#endif  VALIDATE_DATA_H
