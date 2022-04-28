#include "tili.h"

Tili::Tili(QObject * parent) : QObject(parent)
{

    qDebug()<<"RESTAPI DLL Engine = Get tili from database";
    QString site_url="http://localhost:3000/tili";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer ";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);

    reply = dbManager->get(request);
}
Tili::~Tili()
{
    qDebug()<<"At DLL tili destructor";
}




const QString &Tili::getRaTili() const
{
    return RaTili;
}

void Tili::setRaTili(const QString &newRaTili)
{
    RaTili = newRaTili;
}

void Tili::recvTiliFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    RaTili=QString::number(json_obj["id_tili"].toInt())+","+json_obj["tilinumero"].toInt()
            +","+json_obj["saldo"].toDouble();

    qDebug()<<RaTili;
    reply->deleteLater();
    dbManager->deleteLater();
}
/*
void Tili::updateSaldoFromDB(QNetworkReply *reply, QString saldo)
{
    QJsonObject jsonObj;
    jsonObj.insert("Saldo", saldo);

    QString site_url="http://localhost:3000/book/19";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QString credentials="admin:1234";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateBookSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());

    emit sendTiliToMain(saldo);
}
*/

