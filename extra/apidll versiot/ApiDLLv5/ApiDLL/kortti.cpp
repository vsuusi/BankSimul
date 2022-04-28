#include "kortti.h"

kortti::kortti(QObject * parent) : QObject(parent)
{

    qDebug()<<"RESTAPI DLL Engine = Get kortti from database";
    QString site_url="http://localhost:3000/kortti";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);

    reply = dbManager->get(request);
}


kortti::~kortti()
{
    qDebug()<<"At DLL kortti destructor";
}

const QString &kortti::getRaKortti() const
{
    return RaKortti;
}

void kortti::setRaKortti(const QString &newRaKortti)
{
    RaKortti = newRaKortti;
}



void kortti::recvKorttiFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();    
    RaKortti=QString::number(json_obj["id_kortti"].toInt())+","+json_obj["korttinumero"].toInt()
            +","+json_obj["pin"].toInt()+","+json_obj["id_asiakas"].toInt()
            +","+json_obj["id_tili"].toInt();

    qDebug()<<RaKortti;

    reply->deleteLater();
    dbManager->deleteLater();
}

