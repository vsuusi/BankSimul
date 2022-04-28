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
    login(QString pin, QString korttinumero, QObject * parent = nullptr);
    ~login();

    QByteArray token;

    void setToken(const QByteArray &newToken);

    const QByteArray &getToken() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString pin;
    QString korttinumero;
    //QByteArray token;

signals:
    void sendLoginToMain(QString);
    void sendTokenToMain(QByteArray);
    void sendToApiDLL(QByteArray);

public slots:
    void recvTokenFromDB(QNetworkReply *reply);
};

#endif // LOGIN_H
