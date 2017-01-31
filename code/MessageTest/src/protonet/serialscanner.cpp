#include <serialScanner.h>
int nPorts = 0;

serialScanner::serialScanner()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            portNames << info.portName();
            nPorts++;
        }
    }
}

QStringList serialScanner::ports()
{
    return portNames;
}
