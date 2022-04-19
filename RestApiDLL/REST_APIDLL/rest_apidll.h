#ifndef REST_APIDLL_H
#define REST_APIDLL_H

#include "engine.h"
#include "REST_APIDLL_global.h"
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class REST_APIDLL_EXPORT REST_APIDLL : public QObject
{
    Q_OBJECT
public:
    REST_APIDLL(QObject * parent = nullptr);
    ~REST_APIDLL();
    //void getDataFromDB();
    //QString dataFromDB;

private:
    Engine * pEngine;
    QByteArray response_data;

signals:
    void sendDataToExe(QString);

public slots:
    void recvDataFromEngineAsiakas(QNetworkReply *reply);
    void recvLoginFromEngine(QNetworkReply *reply);

};

#endif // REST_APIDLL_H
