#ifndef TILI_H
#define TILI_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class Tili : public QObject
{
    Q_OBJECT
public:
    Tili(QObject * parent = nullptr);
    ~Tili();
    void getTiliDB();

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

signals:
    void sendTiliToMain(QString);

public slots:
    void recvTiliFromDB(QNetworkReply *reply);
};

#endif // TILI_H
