#ifndef RESTAPI_DLLV2_H
#define RESTAPI_DLLV2_H

#include "ApiDLL_global.h"
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "tili.h"
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
    QByteArray getTokenFromApi();
    QByteArray token;

    const QByteArray &getToken() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString pin;
    QString korttinumero;


    Tili * pTili;
    tili_asiakas * pTili_Asiakas;
    asiakas * pAsiakas;
    kortti * pKortti;
    tilitapahtumat * pTilitapahtumat;
    login * pLogin;


signals:
    void sendToExe(QString);
    void sendTokenToExe(QByteArray);
    void QuitEventLoop();

public slots:
    void recvTili(QString);
    void recvTili_Asiakas(QString);
    void recvAsiakas(QString);
    void recvKortti(QString);
    void recvTilitapahtumat(QString);

    void recvLoginSlot(QNetworkReply *reply);

};

#endif // RESTAPI_DLLV2_H
