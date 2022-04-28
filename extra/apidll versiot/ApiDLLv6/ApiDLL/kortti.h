#ifndef KORTTI_H
#define KORTTI_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <login.h>

class kortti : public QObject
{
    Q_OBJECT
public:
    kortti(QObject * parent = nullptr);
    ~kortti();

    QByteArray token = pLogin->getToken();

    void setKorttinumero(const QString &newKorttinumero);

    const QString &getKorttinumero() const;

    void setPin(const QString &newPin);

    const QString &getPin() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

    login * pLogin;

    QString korttinumero;
    QString pin;

signals:
    void sendKorttiToMain(QString, QString);

public slots:
    void recvKorttiFromDB(QNetworkReply *reply);
};

#endif // KORTTI_H
