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

    const QString &getRaTili() const;

    void setRaTili(const QString &newRaTili);

private:
    QNetworkAccessManager *dbManager;
    QNetworkAccessManager *putManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString RaTili;

signals:
    void sendTiliToMain(QString);

public slots:
    void recvTiliFromDB(QNetworkReply *reply);
    //void updateSaldoFromDB(QNetworkReply *reply, QString);
};

#endif // TILI_H
