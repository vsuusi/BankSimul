#include "engine.h"

Engine::Engine(QObject * parent) : QObject(parent)
{
    qDebug()<<"RESTAPI DLL Engine constructor";
}

Engine::~Engine()
{
    qDebug()<<"RESTAPI DLL Engine destructor";
}

void Engine::getDataFromDB()
{
    qDebug()<<"RESTAPI DLL Engine = Get Database";
    QString site_url="http://localhost:3000/asiakas";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvDataFromEngineAsiakas(QNetworkReply*)));
    reply = dbManager->get(request);

    reply->deleteLater();
    dbManager->deleteLater();

}

void Engine::postLoginFromDB(QNetworkReply *reply)
{
    qDebug()<<"RESTAPI DLL Engine = Post Login Database";
    QJsonObject jsonObj; //luodaan JSON objekti ja lisätään data
    jsonObj.insert("pin",pin);

    QString site_url="http://localhost:3000/kortti";
    QNetworkRequest request((site_url));

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvLoginFromEngine(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

    reply->deleteLater();
    loginManager->deleteLater();
}
