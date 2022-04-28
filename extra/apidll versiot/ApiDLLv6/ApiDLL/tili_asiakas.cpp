#include "tili_asiakas.h"

tili_asiakas::tili_asiakas(QObject * parent) : QObject(parent)
{
    qDebug()<<"At DLL tili_asiakas constructor";
    qDebug()<<"RESTAPI DLL Engine = Get tili_asiakas from database";
    QString site_url="http://localhost:3000/tili_asiakas";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer " + token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvTili_AsiakasFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

tili_asiakas::~tili_asiakas()
{
    qDebug()<<"At DLL tili_asiakas destructor";
}

void tili_asiakas::setId_asiakas(const QString &newId_asiakas)
{
    id_asiakas = newId_asiakas;
}

const QString &tili_asiakas::getId_asiakas() const
{
    return id_asiakas;
}

void tili_asiakas::recvTili_AsiakasFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili_asiakas from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    id_asiakas=QString::number(json_obj["id_tili"].toInt())+","+json_obj["id_asiakas"].toInt();

    setId_asiakas(id_asiakas);

    qDebug()<<id_asiakas;

    emit sendTili_AsiakasToMain(id_asiakas);

    reply->deleteLater();
    dbManager->deleteLater();
}

