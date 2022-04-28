#ifndef TILI_H
#define TILI_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <login.h>

class Tili : public QObject
{
    Q_OBJECT
public:
    Tili(QObject * parent = nullptr);
    ~Tili();

    QByteArray token = pLogin->getToken();

    void setTilinumero(const QString &newTilinumero);

    const QString &getTilinumero() const;

    void setSaldo(const QString &newSaldo);

    const QString &getSaldo() const;

private:
    QNetworkAccessManager *dbManager;
    QNetworkAccessManager *putManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString tilinumero;
    QString saldo;

    login * pLogin;

signals:
    void sendTiliToMain(QString, QString);

public slots:
    void recvTiliFromDB(QNetworkReply *reply);
    //void updateSaldoFromDB(QNetworkReply *reply, QString);
};

#endif // TILI_H
