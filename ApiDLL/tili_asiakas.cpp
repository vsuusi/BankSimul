#include "tili_asiakas.h"

tili_asiakas::tili_asiakas(QObject * parent) : QObject(parent)
{

}

tili_asiakas::~tili_asiakas()
{

}

void tili_asiakas::getTili_AsiakasDB()
{
    qDebug()<<"RESTAPI DLL Engine = Get tili_asiakas from database";
    QString site_url="http://localhost:3000/tili_asiakas";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvTili_AsiakasFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

void tili_asiakas::recvTili_AsiakasFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili_asiakas from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString RaTili_Asiakas;
    RaTili_Asiakas=QString::number(json_obj["id_tili"].toInt())+","+json_obj["id_asiakas"].toInt();

    qDebug()<<RaTili_Asiakas;

    emit sendTili_AsiakasToMain(RaTili_Asiakas);

    reply->deleteLater();
    dbManager->deleteLater();
}

