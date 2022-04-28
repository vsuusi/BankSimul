#ifndef KORTTI_H
#define KORTTI_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class kortti : public QObject
{
    Q_OBJECT
public:
    kortti(QObject * parent = nullptr);
    ~kortti();
    void getKorttiDB();

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;

signals:
    void sendKorttiToMain(QString);

public slots:
    void recvKorttiFromDB(QNetworkReply *reply);
};

#endif // KORTTI_H
