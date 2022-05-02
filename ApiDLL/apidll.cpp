#include "apidll.h"


ApiDLL::ApiDLL(QObject *parent) : QObject(parent)
{
    qDebug()<<"RESTAPI DLL constructor";
    pTili_Asiakas = new tili_asiakas(this);
    pAsiakas = new asiakas(this);
    pKortti = new kortti(this);
    pTilitapahtumat = new tilitapahtumat(this);
}

ApiDLL::~ApiDLL()
{
    qDebug()<<"RESTAPI DLL destructor";
    delete pTili_Asiakas;
    pTili_Asiakas = nullptr;
    delete pAsiakas;
    pAsiakas = nullptr;
    delete pKortti;
    pKortti = nullptr;
    delete pTilitapahtumat;
    pTilitapahtumat = nullptr;
}

void ApiDLL::Login(QString pin, QString korttinumero)
{
    QJsonObject jsonObj;
    jsonObj.insert("korttinumero", korttinumero);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvLoginSlot(QNetworkReply*)));

    reply = dbManager->post(request, QJsonDocument(jsonObj).toJson());
}



const QByteArray &ApiDLL::getToken() const
{
    return token;
}

void ApiDLL::recvLoginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    token = "Bearer " + response_data;
    emit sendTokenToExe(token);
}


void ApiDLL::Asiakas(QByteArray kayttisToken, int asiakasId)
{
    QString id = QString::number(asiakasId);
    QString site_url="http://localhost:3000/asiakas/"+id;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(kayttisToken));
    asiakasManager = new QNetworkAccessManager(this);
    connect(asiakasManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvAsiakasSlot(QNetworkReply*)));
    asiakasreply = asiakasManager->get(request);
}


void ApiDLL::recvAsiakasSlot(QNetworkReply *asiakasreply)
{
    QByteArray asiakasresponse_data=asiakasreply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(asiakasresponse_data);
    QJsonArray json_array = json_doc.array();
    QString RaAsiakas;
    foreach(const QJsonValue &value, json_array)
    {
    QJsonObject json_obj = value.toObject();
    RaAsiakas=QString::number(json_obj["idasiakas"].toInt())+","+json_obj["nimi"].toString()+
            ","+json_obj["lahiosoite"].toString()+","+json_obj["puhelinnumero"].toString();
    }

    emit sendAsiakasToExe(RaAsiakas);

    asiakasreply->deleteLater();
    asiakasManager->deleteLater();
}


void ApiDLL::Tili(QByteArray kayttisToken, int tiliId)
{
    QString id = QString::number(tiliId);
    QString site_url="http://localhost:3000/tili/"+id;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(kayttisToken));
    tiliManager = new QNetworkAccessManager(this);
    connect(tiliManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvTiliSlot(QNetworkReply*)));
    tilireply = tiliManager->get(request);
}

void ApiDLL::recvTiliSlot(QNetworkReply *tilireply)
{
    QByteArray tiliresponse_data=tilireply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(tiliresponse_data);
    QJsonObject json_obj = json_doc.object();
    QString tili_dataId;
    QString tili_dataNumero;
    QString tili_dataSaldo;

    tili_dataId = QString::number(json_obj["idtili"].toInt())+",";
    tili_dataNumero = json_obj["tilinumero"].toString()+",";
    tili_dataSaldo = QString::number(json_obj["saldo"].toDouble());

    emit sendTiliToExe(tili_dataId, tili_dataNumero, tili_dataSaldo);

    tilireply->deleteLater();
    tiliManager->deleteLater();
}










