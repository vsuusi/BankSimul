#include "restapi_dllv2.h"

RestApi_DLLv2::RestApi_DLLv2(QObject *parent) : QObject(parent)
{
    qDebug()<<"RESTAPI DLL constructor";
    pTili = new Tili(this);
    connect(pTili, SIGNAL(sendTiliToMain()),this,SLOT(recvTili()));

    pTili_Asiakas = new tili_asiakas(this);
    connect(pTili_Asiakas, SIGNAL(sendTiliToMain()),this,SLOT(recvTili_Asiakas()));

    pAsiakas = new asiakas(this);
    connect(pAsiakas, SIGNAL(sendTiliToMain()),this,SLOT(recvAsiakas()));

    pKortti = new kortti(this);
    connect(pKortti, SIGNAL(sendTiliToMain()),this,SLOT(recvKortti()));

    pTilitapahtumat = new tilitapahtumat(this);
    connect(pTilitapahtumat, SIGNAL(sendTiliToMain()),this,SLOT(recvTilitapahtumat()));
}

RestApi_DLLv2::~RestApi_DLLv2()
{
    qDebug()<<"RESTAPI DLL destructor";
    disconnect(pTili, SIGNAL(sendTiliToMain()),this,SLOT(recvTili()));
    delete pTili;
    pTili = nullptr;

    disconnect(pTili_Asiakas, SIGNAL(sendTiliToMain()),this,SLOT(recvTili_Asiakas()));
    delete pTili_Asiakas;
    pTili_Asiakas = nullptr;

    disconnect(pAsiakas, SIGNAL(sendTiliToMain()),this,SLOT(recvAsiakas()));
    delete pAsiakas;
    pAsiakas = nullptr;

    disconnect(pKortti, SIGNAL(sendTiliToMain()),this,SLOT(recvKortti()));
    delete pKortti;
    pKortti = nullptr;

    disconnect(pTilitapahtumat, SIGNAL(sendTiliToMain()),this,SLOT(recvTilitapahtumat()));
    delete pTilitapahtumat;
    pTilitapahtumat = nullptr;
}

void RestApi_DLLv2::recvTili(QString Tili)
{
    qDebug()<<"At DLL SLOT function = recvTili";
    emit sendToExe(Tili);
}

void RestApi_DLLv2::recvTili_Asiakas(QString Tili_Asiakas)
{
    qDebug()<<"At DLL SLOT function = recvTili_Asiakas)";
    emit sendToExe(Tili_Asiakas);
}

void RestApi_DLLv2::recvAsiakas(QString Asiakas)
{
    qDebug()<<"At DLL SLOT function = recvAsiakas)";
    emit sendToExe(Asiakas);
}

void RestApi_DLLv2::recvKortti(QString Kortti)
{
    qDebug()<<"At DLL SLOT function = recvAsiakas)";
    emit sendToExe(Kortti);
}

void RestApi_DLLv2::recvTilitapahtumat(QString Tilitapahtumat)
{
    qDebug()<<"At DLL SLOT function = recvAsiakas)";
    emit sendToExe(Tilitapahtumat);
}
