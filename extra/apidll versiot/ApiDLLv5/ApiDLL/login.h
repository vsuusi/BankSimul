#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class login : public QObject
{
    Q_OBJECT
public:
    login(QObject *parent = nullptr);
    ~login();

    QByteArray *getTokenPtr() const;

    const QByteArray &getToken() const;
    void setToken(const QByteArray &newToken);

    const QString &getKorttinumero() const;
    void setKorttinumero(const QString &newKorttinumero);

    const QString &getPin() const;
    void setPin(const QString &newPin);

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString pin;
    QString korttinumero;
    QByteArray token;

signals:
    void sendLoginToMain(QString);
    void sendTokenToMain(QString);
    void sendToApiDLL(QByteArray);

public slots:
    void recvLoginFromDB(QNetworkReply *reply);
};

#endif // LOGIN_H
