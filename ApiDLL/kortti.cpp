#include "kortti.h"

kortti::kortti(QObject * parent) : QObject(parent)
{

}

kortti::~kortti()
{

}

void kortti::getKorttiDB()
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
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvKorttiFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

void kortti::recvKorttiFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString RaKortti;
    RaKortti=QString::number(json_obj["id_kortti"].toInt())+","+json_obj["korttinumero"].toInt()
            +","+json_obj["pin"].toInt()+","+json_obj["id_asiakas"].toInt()
            +","+json_obj["id_tili"].toInt();

    qDebug()<<RaKortti;

    emit sendKorttiToMain(RaKortti);

    reply->deleteLater();
    dbManager->deleteLater();
}

