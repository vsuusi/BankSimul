#include "login.h"

login::login(QString pin, QString korttinumero, QObject *parent) : QObject(parent)
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
    connect(dbManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvTokenFromDB(QNetworkReply*)));

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


void login::recvTokenFromDB(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"recvloginfromDB";
    token = "Bearer " + response_data;
    setToken(token);
    qDebug() << token;



    // emit sendTokenToMain(token);




////    emit sendLoginToMain(pin);
////    emit sendTokenToMain(token);
}
