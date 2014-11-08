#include "validate_data.h"

ValidateData::ValidateData(){}

quint8 ValidateData::validateData(quint16 msg, QByteArray data){
    if (msg != 2000) return 2;
    if (data.size() != 14) return 1; //If length of array != 14

    if (data.at(13) < 0 || data.at(13) > 2)   //The last byte should be between 0 and 2
        return 1;

    return 0;
}
