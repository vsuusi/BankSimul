#include "lukija_dll.h"




Lukija_Dll::Lukija_Dll(QObject *parent): QObject(parent)
{
    pLukija_Dll_Engine = new Lukija_Dll_Engine(this);
    connect(pLukija_Dll_Engine,SIGNAL(returnValueToLukija_Dll(QString)),
            this,SLOT(recvValueToLukija_Dll(QString)));
}

Lukija_Dll::~Lukija_Dll()
{
    disconnect(pLukija_Dll_Engine,SIGNAL(returnValueToLukija_Dll(QString)),
              this,SLOT(recvValueToLukija_Dll(QString)));
    delete pLukija_Dll_Engine;
    pLukija_Dll_Engine = nullptr;
}

void Lukija_Dll::recvValueToLukija_Dll(QString response)
{
    emit sendValueToExe(response);
    qDebug() <<response;
}


