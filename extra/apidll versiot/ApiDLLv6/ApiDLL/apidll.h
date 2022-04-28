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
    void LoginDB(QString pin, QString korttinumero);
    QByteArray token;

    void TokenDB(QByteArray token);

    void AsiakasDB(QString nimi, QString lahiosoite, QString puhelinnumero);

    void TiliDB(QString tilinumero, QString saldo);

    void KorttiDB(QString korttinumero, QString pin);

    void Tili_AsiakasDB(QString tili_asiakas);

private:
    Tili * pTili;
    tili_asiakas * pTili_Asiakas;
    asiakas * pAsiakas;
    kortti * pKortti;
    tilitapahtumat * pTilitapahtumat;
    login * pLogin;


signals:
    void sendToAsiakasExe(QString, QString, QString);
    void sendTiliToExe(QString, QString);
    void sendKorttiToExe(QString, QString);
    void sendTili_AsiakasToExe(QString);
    void sendTilitapahtumatToExe(QString);
    void sendToken(QByteArray);

public slots:
    void recvTilitapahtumat(QString);

};

#endif // RESTAPI_DLLV2_H
