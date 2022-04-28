#include "kortti.h"

kortti::kortti(QObject * parent) : QObject(parent)
{
    qDebug()<<"At DLL kortti constructor";
    qDebug()<<"RESTAPI DLL Engine = Get kortti from database";
    QString site_url="http://localhost:3000/kortti";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer " + token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvKorttiFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

kortti::~kortti()
{
    qDebug()<<"At DLL kortti destructor";
}

void kortti::setKorttinumero(const QString &newKorttinumero)
{
    korttinumero = newKorttinumero;
}

const QString &kortti::getKorttinumero() const
{
    return korttinumero;
}

void kortti::setPin(const QString &newPin)
{
    pin = newPin;
}

const QString &kortti::getPin() const
{
    return pin;
}


void kortti::recvKorttiFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    korttinumero=QString::number(json_obj["id_kortti"].toInt())+","+json_obj["korttinumero"].toInt()+
            ","+json_obj["id_asiakas"].toInt()+","+json_obj["id_tili"].toInt();
    pin=QString::number(json_obj["id_kortti"].toInt())+","+json_obj["pin"].toInt()+
            ","+json_obj["id_asiakas"].toInt()+","+json_obj["id_tili"].toInt();

    setKorttinumero(korttinumero);
    setPin(pin);

    qDebug()<<korttinumero + " " + pin;

    emit sendKorttiToMain(korttinumero, pin);

    reply->deleteLater();
    dbManager->deleteLater();
}

