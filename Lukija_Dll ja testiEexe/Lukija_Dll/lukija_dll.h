#ifndef LUKIJA_DLL_H
#define LUKIJA_DLL_H

#include "Lukija_Dll_global.h"
#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <QDebug>
#include "lukija_dll_engine.h"

class LUKIJA_DLL_EXPORT Lukija_Dll : public QObject
{
    Q_OBJECT
public:
    Lukija_Dll(QObject *parent = nullptr);
    ~Lukija_Dll();
    void recvData(QString);



signals:

    void sendValueToExe(QString);



public slots:

    void recvValueToLukija_Dll(QString response);


private:

    Lukija_Dll_Engine * pLukija_Dll_Engine;


};

#endif // LUKIJA_DLL_H
