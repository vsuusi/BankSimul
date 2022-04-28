#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class tilitapahtumat : public QObject
{
    Q_OBJECT
public:
    tilitapahtumat(QObject * parent = nullptr);
    ~tilitapahtumat();
    void getTilitapahtumatDB();

    const QString &getRaTilitapahtumat() const;
    void setRaTilitapahtumat(const QString &newRaTilitapahtumat);

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QString RaTilitapahtumat;


public slots:
    void recvTilitapahtumatFromDB(QNetworkReply *reply);
};

#endif // TILITAPAHTUMAT_H
