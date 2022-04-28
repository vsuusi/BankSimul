#include "tili.h"

Tili::Tili(QObject * parent) : QObject(parent)
{
    qDebug()<<"At DLL tili constructor";
    qDebug()<<"RESTAPI DLL Engine = Get tili from database";
    QString site_url="http://localhost:3000/tili";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer " + token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvTiliFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

Tili::~Tili()
{
    qDebug()<<"At DLL tili destructor";
}

void Tili::setTilinumero(const QString &newTilinumero)
{
    tilinumero = newTilinumero;
}

const QString &Tili::getTilinumero() const
{
    return tilinumero;
}

void Tili::setSaldo(const QString &newSaldo)
{
    saldo = newSaldo;
}

const QString &Tili::getSaldo() const
{
    return saldo;
}

void Tili::recvTiliFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive tili from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    tilinumero=QString::number(json_obj["id_tili"].toInt())+","+json_obj["tilinumero"].toInt();
    saldo=QString::number(json_obj["id_tili"].toInt())+","+json_obj["saldo"].toDouble();

    setTilinumero(tilinumero);
    setSaldo(saldo);

    qDebug()<<tilinumero + " " + saldo;

    emit sendTiliToMain(tilinumero, saldo);

    reply->deleteLater();
    dbManager->deleteLater();
}

