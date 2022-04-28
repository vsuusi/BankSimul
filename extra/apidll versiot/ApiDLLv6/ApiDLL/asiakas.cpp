#include "asiakas.h"

asiakas::asiakas(QObject *parent) : QObject(parent)
{
    qDebug()<<"At DLL asiakas constructor";
    qDebug()<<"RESTAPI DLL Engine = Get asiakas from database";
    QString site_url="http://localhost:3000/asiakas";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer " + token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvAsiakasFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

asiakas::~asiakas()
{
    qDebug()<<"At DLL asiakas destructor";
}

void asiakas::setNimi(const QString &newNimi)
{
    nimi = newNimi;
}

const QString &asiakas::getNimi() const
{
    return nimi;
}

void asiakas::setLahiosoite(const QString &newLahiosoite)
{
    lahiosoite = newLahiosoite;
}

const QString &asiakas::getLahiosoite() const
{
    return lahiosoite;
}

void asiakas::setPuhelinnumero(const QString &newPuhelinnumero)
{
    puhelinnumero = newPuhelinnumero;
}

const QString &asiakas::getPuhelinnumero() const
{
    return puhelinnumero;
}

void asiakas::recvAsiakasFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = Receive asiakas from database";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    nimi=QString::number(json_obj["id_asiakas"].toInt())+","+json_obj["nimi"].toString();
    lahiosoite=QString::number(json_obj["id_asiakas"].toInt())+","+json_obj["lahiosoite"].toString();
    puhelinnumero=QString::number(json_obj["id_asiakas"].toInt())+","+json_obj["puhelinnumero"].toInt();

    setNimi(nimi);
    setLahiosoite(lahiosoite);
    setPuhelinnumero(puhelinnumero);

    qDebug()<<nimi + " " + lahiosoite + " " + puhelinnumero;

    emit sendAsiakasToMain(nimi, lahiosoite, puhelinnumero);

    reply->deleteLater();
    dbManager->deleteLater();
}
