#include "login.h"

login::login(QObject *parent) : QObject(parent)
{
    qDebug()<<"At Dll login constructor";
    postLogin();
}

login::~login()
{
    qDebug()<<"At DLL login destructor";
}

void login::postLogin()
{
    QJsonObject jsonObj;
    jsonObj.insert("korttinumero", korttinumero);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvLoginfromDB(QNetworkReply*)));

    reply = dbManager->post(request, QJsonDocument(jsonObj).toJson());
}

const QString &login::getPin() const
{
    return pin;
}

const QString &login::getToken() const
{
    return token;
}

void login::recvLoginFromDB(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    token = "Bearer " + response_data;

    emit sendLoginToMain(pin);
    emit sendTokenToMain(token);
}
