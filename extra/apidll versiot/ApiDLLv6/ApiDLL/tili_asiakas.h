#ifndef TILI_ASIAKAS_H
#define TILI_ASIAKAS_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <login.h>

class tili_asiakas : public QObject
{
    Q_OBJECT
public:
    tili_asiakas(QObject * parent = nullptr);
    ~tili_asiakas();

    QByteArray token = pLogin->getToken();

    void setId_asiakas(const QString &newId_asiakas);

    const QString &getId_asiakas() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

    login * pLogin;

    QString id_asiakas;

signals:
    void sendTili_AsiakasToMain(QString);

public slots:
    void recvTili_AsiakasFromDB(QNetworkReply *reply);
};

#endif // TILI_ASIAKAS_H
