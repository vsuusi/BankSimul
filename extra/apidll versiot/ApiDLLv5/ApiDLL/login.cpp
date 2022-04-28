#include "login.h"



login::login(QObject *parent):
    QObject(parent)
{
    qDebug()<<"At Dll login constructor";
    qDebug() << "pin = " + pin;
    qDebug() << "korttinumero " + korttinumero;
    QJsonObject jsonObj;
    jsonObj.insert("korttinumero", korttinumero);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvLoginFromDB(QNetworkReply*)));

    reply = dbManager->post(request, QJsonDocument(jsonObj).toJson());
}

login::~login()
{
    qDebug()<<"At DLL login destructor";
}

const QByteArray &login::getToken() const
{
    return token;
}

void login::setToken(const QByteArray &newToken)
{
    token = newToken;
}

const QString &login::getKorttinumero() const
{
    return korttinumero;
}

void login::setKorttinumero(const QString &newKorttinumero)
{
    korttinumero = newKorttinumero;
}

const QString &login::getPin() const
{
    return pin;
}

void login::setPin(const QString &newPin)
{
    pin = newPin;
}

void login::recvLoginFromDB(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"recvloginfromDB";
    token = "Bearer " + response_data;
    qDebug() << token;




    // emit sendToApiDLL(token);




////    emit sendLoginToMain(pin);
////    emit sendTokenToMain(token);
}
