#include "apidll.h"


ApiDLL::ApiDLL(QObject *parent) : QObject(parent)
{
    qDebug()<<"RESTAPI DLL constructor";
    pTili = new Tili(this);
//    connect(pTili, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili(QString)));

    pTili_Asiakas = new tili_asiakas(this);
//    connect(pTili_Asiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTili_Asiakas(QString)));

    pAsiakas = new asiakas(this);
//    connect(pAsiakas, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvAsiakas(QString)));

    pKortti = new kortti(this);
//    connect(pKortti, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvKortti(QString)));

    pTilitapahtumat = new tilitapahtumat(this);
//    connect(pTilitapahtumat, SIGNAL(sendTiliToMain(QString)),this,SLOT(recvTilitapahtumat(QString)));


}

ApiDLL::~ApiDLL()
{

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
//    delete pLogin;
//    pLogin = nullptr;

}

void ApiDLL::Login(QString pin, QString korttinumero)
{
    // pLogin = new login(pin, korttinumero);
//    qDebug() << "pin = " + pin;
//    qDebug() << "korttinumero " + korttinumero;
    QJsonObject jsonObj;
    jsonObj.insert("korttinumero", korttinumero);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvLoginSlot(QNetworkReply*)));

    reply = dbManager->post(request, QJsonDocument(jsonObj).toJson());
}

const QByteArray &ApiDLL::getToken() const
{
    return token;
}

void ApiDLL::recvLoginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    token = "Bearer " + response_data;
    // token = response_data;
   //  emit QuitEventLoop();
    emit sendTokenToExe(token);
}






void ApiDLL::recvTili(QString RaTili)
{
    qDebug()<<"At DLL SLOT function = recvTili";
    QString tili = pTili->getRaTili();
    qDebug()<<"tili="+tili;
    emit sendToExe(RaTili);
}

void ApiDLL::recvTili_Asiakas(QString RaTili_Asiakas)
{
    qDebug()<<"At DLL SLOT function = recvTili_Asiakas";
    emit sendToExe(RaTili_Asiakas);
}

void ApiDLL::recvAsiakas(QString RaAsiakas)
{
    qDebug()<<"At DLL SLOT function = recvAsiakas";
    emit sendToExe(RaAsiakas);
}

void ApiDLL::recvKortti(QString RaKortti)
{
    qDebug()<<"At DLL SLOT function = recvKortti";
    emit sendToExe(RaKortti);
}

void ApiDLL::recvTilitapahtumat(QString RaTilitapahtumat)
{
    qDebug()<<"At DLL SLOT function = recvTilitapahtumat";
    emit sendToExe(RaTilitapahtumat);
}






