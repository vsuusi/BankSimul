#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <login.h>

class asiakas : public QObject
{
    Q_OBJECT
public:
    asiakas(QObject * parent = nullptr);
    ~asiakas();

    QByteArray token = pLogin->getToken();

    void setNimi(const QString &newNimi);

    const QString &getNimi() const;

    const QString &getLahiosoite() const;

    void setLahiosoite(const QString &newLahiosoite);

    void setPuhelinnumero(const QString &newPuhelinnumero);

    const QString &getPuhelinnumero() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

    login * pLogin;

    QString nimi;
    QString lahiosoite;
    QString puhelinnumero;

signals:
    void sendAsiakasToMain(QString, QString, QString);

public slots:
    void recvAsiakasFromDB(QNetworkReply *reply);
};

#endif // ASIAKAS_H
