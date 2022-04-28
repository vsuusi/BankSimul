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

class ApiDLL: public QObject
{
    Q_OBJECT


public:
    void APIDLL_EXPORT saaToken();
    QByteArray returnFromLogin();
    void APIDLL_EXPORT saaPinJaKortti();
    QString return2FromLogin();
    void APIDLL_EXPORT saaTili();
    QString returnFromTili();
    void APIDLL_EXPORT saaTili_Asiakas();
    QString returnFromTili_Asiakas();
    void APIDLL_EXPORT saaAasi();
    QString returnFromAsiakas();
    void APIDLL_EXPORT saaKortti();
    QString returnFromKortti();
    void APIDLL_EXPORT saaTiliTapahtumat();
    QString returnFromTiliTapahtumat();



private:
    Tili *pTili;
    tili_asiakas *pTili_Asiakas;
    asiakas *pAsiakas;
    kortti *pKortti;
    tilitapahtumat *pTilitapahtumat;
    login *pLogin;
    QByteArray tokenValue;
    QString pinValue;
    QString korttiValue;
    QString tiliValue;
    QString tili_aValue;
    QString asiakasValue;
    QString RaKorttiValue;
    QString tiliTapahtumaValue;




};

#endif // RESTAPI_DLLV2_H
