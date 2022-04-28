#include "restapi_dllv2.h"

RestApi_DLLv2::RestApi_DLLv2(QObject *parent) : QObject(parent)
{
    qDebug()<<"RESTAPI DLL constructor";
    pTili = new Tili(this);
    connect(pTili, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili(QString)));

    pTili_Asiakas = new tili_asiakas(this);
    connect(pTili_Asiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili_Asiakas(QString)));

    pAsiakas = new asiakas(this);
    connect(pAsiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvAsiakas(QString)));

    pKortti = new kortti(this);
    connect(pKortti, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvKortti(QString)));

    pTilitapahtumat = new tilitapahtumat(this);
    connect(pTilitapahtumat, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTilitapahtumat(QString)));   
}

RestApi_DLLv2::~RestApi_DLLv2()
{

    qDebug()<<"RESTAPI DLL destructor";
    disconnect(pTili, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili(QString)));
    delete pTili;
    pTili = nullptr;

    disconnect(pTili_Asiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili_Asiakas(QString)));
    delete pTili_Asiakas;
    pTili_Asiakas = nullptr;

    disconnect(pAsiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvAsiakas(QString)));
    delete pAsiakas;
    pAsiakas = nullptr;

    disconnect(pKortti, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvKortti(QString)));
    delete pKortti;
    pKortti = nullptr;

    disconnect(pTilitapahtumat, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTilitapahtumat(QString)));
    delete pTilitapahtumat;
    pTilitapahtumat = nullptr;

}

void RestApi_DLLv2::recvTili(QString RaTili)
{
    qDebug()<<"At DLL SLOT function = recvTili";
    QString tili = pTili->getRaTili();
    qDebug()<<"tili="+tili;
    emit sendToExe(RaTili);
}

void RestApi_DLLv2::recvTili_Asiakas(QString RaTili_Asiakas)
{
    qDebug()<<"At DLL SLOT function = recvTili_Asiakas";
    emit sendToExe(RaTili_Asiakas);
}

void RestApi_DLLv2::recvAsiakas(QString RaAsiakas)
{
    qDebug()<<"At DLL SLOT function = recvAsiakas";
    emit sendToExe(RaAsiakas);
}

void RestApi_DLLv2::recvKortti(QString RaKortti)
{
    qDebug()<<"At DLL SLOT function = recvKortti";
    emit sendToExe(RaKortti);
}

void RestApi_DLLv2::recvTilitapahtumat(QString RaTilitapahtumat)
{
    qDebug()<<"At DLL SLOT function = recvTilitapahtumat";
    emit sendToExe(RaTilitapahtumat);
}

void RestApi_DLLv2::recvLogin(QString)
{
    qDebug()<<"At DLL SLOT function = recvLogin";
    QString pin = pLogin->getPin();
    qDebug()<<pin;
    emit sendToExe(pin);
}

void RestApi_DLLv2::recvToken(QString)
{
    qDebug()<<"At DLL SLOT function = recvToken";
    QString token = pLogin->getPin();
    qDebug()<<token;
    emit sendToExe(token);
}
