#ifndef TILI_ASIAKAS_H
#define TILI_ASIAKAS_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class tili_asiakas : public QObject
{
    Q_OBJECT
public:
    tili_asiakas(QObject * parent = nullptr);
    ~tili_asiakas();
    void getTili_AsiakasDB();

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

signals:
    void sendTili_AsiakasToMain(QString);

public slots:
    void recvTili_AsiakasFromDB(QNetworkReply *reply);
};

#endif // TILI_ASIAKAS_H
