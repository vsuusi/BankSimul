#include "rest_apidll.h"

REST_APIDLL::REST_APIDLL(QObject *parent) : QObject(parent)
{
    qDebug()<<"RESTAPI DLL constructor";
    pEngine = new Engine(this);
    connect(pEngine, SIGNAL(sendToMainClass()),this,SLOT(recvDataFromEngineAsiakas()));
}

REST_APIDLL::~REST_APIDLL()
{
    qDebug()<<"RESTAPI DLL destructor";
    disconnect(pEngine, SIGNAL(sendToMainClass()),this,SLOT(recvDataFromEngineAsiakas()));
    delete pEngine;
    pEngine = nullptr;
}

void REST_APIDLL::recvDataFromEngineAsiakas(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = receive data from engine";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString data;
    data=QString::number(json_obj["id_asiakas"].toInt())+","+json_obj["nimi"].toString()
            +","+json_obj["lahiosoite"].toString()+","+json_obj["puhelinnumero"].toString();

    qDebug()<<data;

    emit sendDataToExe(data);

    //reply->deleteLater();
    //dbManager->deleteLater();
}

void REST_APIDLL::recvLoginFromEngine(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL = receive login from engine";
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString data;
    data=QString::number(json_obj["id_kortti"].toInt())+","+json_obj["kortinnumero"].toInt()+","+json_obj["pin"].toString();

    qDebug()<<data;

    emit sendDataToExe(data);

    //reply->deleteLater();
    //dbManager->deleteLater();
}


