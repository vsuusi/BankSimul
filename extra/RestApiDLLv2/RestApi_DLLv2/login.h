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
    login(QObject * parent = nullptr);
    ~login();
    void postLogin();

    const QString &getPin() const;

    const QString &getToken() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString pin;
    QString korttinumero;
    QString token;

signals:
    void sendLoginToMain(QString);
    void sendTokenToMain(QString);

public slots:
    void recvLoginFromDB(QNetworkReply *reply);
};

#endif // LOGIN_H
