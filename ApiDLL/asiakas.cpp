#include "asiakas.h"

asiakas::asiakas(QObject *parent) : QObject(parent)
{

    // pAsiakas = new asiakas(this);
    // connect(pAsiakas, SIGNAL(sendAsiakasToMain()),this,SLOT(recvAsiakas()));
}

asiakas::~asiakas()
{

}

void asiakas::getAsiakasDB()
{
    qDebug()<<"RESTAPI DLL Engine = Get asiakas from database";
    QString site_url="http://localhost:3000/asiakas";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvAsiakasFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

void asiakas::recvAsiakasFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive asiakas from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString RaAsiakas;
    RaAsiakas=QString::number(json_obj["id_asiakas"].toInt())+","+json_obj["nimi"].toString()
            +","+json_obj["lahiosoite"].toString()+","+json_obj["puhelinnumero"].toInt();

    qDebug()<<RaAsiakas;

    emit sendAsiakasToMain(RaAsiakas);

    reply->deleteLater();
    dbManager->deleteLater();
}
