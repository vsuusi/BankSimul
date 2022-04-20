#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class asiakas : public QObject
{
    Q_OBJECT
public:
    asiakas(QObject * parent = nullptr);
    ~asiakas();
    void getAsiakasDB();

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

signals:
    void sendAsiakasToMain(QString);

public slots:
    void recvAsiakasFromDB(QNetworkReply *reply);
};

#endif // ASIAKAS_H
