#ifndef RESTAPI_DLLV2_H
#define RESTAPI_DLLV2_H

#include "RestApi_DLLv2_global.h"
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

class RESTAPI_DLLV2_EXPORT RestApi_DLLv2 : public QObject
{
    Q_OBJECT
public:
    RestApi_DLLv2(QObject *parent);
    ~RestApi_DLLv2();

private:
    Tili * pTili;
    tili_asiakas * pTili_Asiakas;
    asiakas * pAsiakas;
    kortti * pKortti;
    tilitapahtumat * pTilitapahtumat;
    login * pLogin;

signals:
    void sendToExe(QString);

public slots:
    void recvTili(QString);
    void recvTili_Asiakas(QString);
    void recvAsiakas(QString);
    void recvKortti(QString);
    void recvTilitapahtumat(QString);
    void recvLogin(QString);
    void recvToken(QString);
};

#endif // RESTAPI_DLLV2_H
