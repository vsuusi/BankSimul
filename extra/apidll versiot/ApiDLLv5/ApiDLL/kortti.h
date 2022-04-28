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

    const QString &getRaKortti() const;
    void setRaKortti(const QString &newRaKortti);

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QString RaKortti;



public slots:
    void recvKorttiFromDB(QNetworkReply *reply);
};

#endif // KORTTI_H
