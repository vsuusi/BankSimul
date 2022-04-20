#include "tili.h"

Tili::Tili(QObject * parent) : QObject(parent)
{
    qDebug()<<"At DLL tili constructor";
}

Tili::~Tili()
{
    qDebug()<<"At DLL tili destructor";
}

void Tili::getTiliDB()
{
    qDebug()<<"RESTAPI DLL Engine = Get tili from database";
    QString site_url="http://localhost:3000/tili";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvTiliFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

void Tili::recvTiliFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString data;
    data=QString::number(json_obj["id_tili"].toInt())+","+json_obj["tilinumero"].toInt()
            +","+json_obj["saldo"].toDouble();

    qDebug()<<data;

    emit sendTiliToMain(data);

    reply->deleteLater();
    dbManager->deleteLater();
}
