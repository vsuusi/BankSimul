#include "apidll.h"


ApiDLL::ApiDLL(QObject *parent) : QObject(parent)
{
/*    qDebug()<<"RESTAPI DLL constructor";
    pTili = new Tili(this);
//    connect(pTili, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili(QString)));

    pTili_Asiakas = new tili_asiakas(this);
//    connect(pTili_Asiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili_Asiakas(QString)));

   // pAsiakas = new asiakas(this);
//    connect(pAsiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvAsiakas(QString)));

    pKortti = new kortti(this);
//    connect(pKortti, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvKortti(QString)));

    pTilitapahtumat = new tilitapahtumat(this);
//    connect(pTilitapahtumat, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTilitapahtumat(QString)));

*/
}

ApiDLL::~ApiDLL()
{
/*
    qDebug()<<"RESTAPI DLL destructor";
    delete pTili;
    pTili = nullptr;
    delete pTili_Asiakas;
    pTili_Asiakas = nullptr;
    delete pAsiakas;
    pAsiakas = nullptr;
    delete pKortti;
    pKortti = nullptr;
    delete pTilitapahtumat;
    pTilitapahtumat = nullptr;
    delete pLogin;
    pLogin = nullptr;
*/
}

void ApiDLL::LoginDB(QString pin, QString korttinumero)
{
    pLogin = new login(pin, korttinumero);
    // QThread::sleep(3000);
    qDebug() << "pin = " + pin;
    qDebug() << "korttinumero " + korttinumero;
    //emit sendToken(token);
}

void ApiDLL::TokenDB(QByteArray token)
{
   token = pLogin->getToken();
   emit sendToken(token);
}

void ApiDLL::AsiakasDB(QString nimi, QString lahiosoite, QString puhelinnumero)
{
    pAsiakas = new asiakas(this);
    nimi = pAsiakas->getNimi();
    lahiosoite = pAsiakas->getLahiosoite();
    puhelinnumero = pAsiakas->getPuhelinnumero();
    emit sendToAsiakasExe(nimi, lahiosoite, puhelinnumero);
}

void ApiDLL::TiliDB(QString tilinumero, QString saldo)
{
    pTili = new Tili(this);
    tilinumero = pTili->getTilinumero();
    saldo = pTili->getSaldo();
    emit sendTiliToExe(tilinumero, saldo);
}

void ApiDLL::KorttiDB(QString korttinumero, QString pin)
{
    pKortti = new kortti(this);
    korttinumero = pKortti->getKorttinumero();
    pin = pKortti->getPin();
    emit sendKorttiToExe(korttinumero, pin);
}

void ApiDLL::Tili_AsiakasDB(QString tiliAsiakas)
{
    pTili_Asiakas = new tili_asiakas(this);
    tiliAsiakas = pTili_Asiakas->getId_asiakas();
    emit sendTili_AsiakasToExe(tiliAsiakas);
}


void ApiDLL::recvTilitapahtumat(QString RaTilitapahtumat)
{
    qDebug()<<"At DLL SLOT function = recvTilitapahtumat";
    emit sendTilitapahtumatToExe(RaTilitapahtumat);
}




