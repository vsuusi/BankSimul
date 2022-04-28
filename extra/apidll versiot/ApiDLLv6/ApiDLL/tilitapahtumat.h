#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <login.h>

class tilitapahtumat : public QObject
{
    Q_OBJECT
public:
    tilitapahtumat(QObject * parent = nullptr);
    ~tilitapahtumat();

    QByteArray token = pLogin->getToken();

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

    login * pLogin;

signals:
    void sendTilitapahtumatToMain(QString);

public slots:
    void recvTilitapahtumatFromDB(QNetworkReply *reply);
};

#endif // TILITAPAHTUMAT_H
