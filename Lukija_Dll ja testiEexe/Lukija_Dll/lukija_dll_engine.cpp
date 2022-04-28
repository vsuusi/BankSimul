#include "lukija_dll_engine.h"


QSerialPort *serial;
Lukija_Dll_Engine::Lukija_Dll_Engine(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    serial->setPortName("com4");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    connect(serial,SIGNAL(readyRead()),
            this,SLOT(recvResponse()));

}

Lukija_Dll_Engine::~Lukija_Dll_Engine()
{
    serial->close();
}



void Lukija_Dll_Engine::recvResponse()
{
    QByteArray ba = serial->readAll();

    ba = ba.simplified();
    ba = ba.mid(1,4);
    qDebug() <<ba;
    QString response = QString::fromUtf8(ba);
    emit returnValueToLukija_Dll(response);
};


