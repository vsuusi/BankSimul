#ifndef RESTAPI_DLLV2_H
#define RESTAPI_DLLV2_H

#include "ApiDLL_global.h"
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "tili_asiakas.h"
#include "kortti.h"
#include "asiakas.h"
#include "tilitapahtumat.h"
#include "login.h"

class APIDLL_EXPORT ApiDLL : public QObject
{
    Q_OBJECT
public:
    ApiDLL(QObject *parent);
    ~ApiDLL();
    void Login(QString pin, QString korttinumero);
    void Asiakas(QByteArray kayttisToken, int asiakasId);
    void Tili(QByteArray kayttisToken, int korttiId);


    QByteArray getTokenFromApi();
    QByteArray token;

    const QByteArray &getToken() const;

    int asiakasId;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString pin;
    QString korttinumero;

    QNetworkAccessManager *asiakasManager;
    QNetworkReply *asiakasreply;
    QByteArray asiakasresponse_data;

    QNetworkAccessManager *tiliManager;
    QNetworkReply *tilireply;
    QByteArray tiliresponse_data;

    tili_asiakas * pTili_Asiakas;
    asiakas * pAsiakas;
    kortti * pKortti;
    tilitapahtumat * pTilitapahtumat;
    login * pLogin;


signals:
    void sendToExe(QString);

    void sendTokenToExe(QByteArray);
    void sendAsiakasToExe(QString);
    void sendTiliToExe(QString, QString, QString);

    void QuitEventLoop();

public slots:

    void recvTiliSlot(QNetworkReply *reply);
    void recvLoginSlot(QNetworkReply *reply);
    void recvAsiakasSlot(QNetworkReply *reply);

};

#endif // RESTAPI_DLLV2_H
