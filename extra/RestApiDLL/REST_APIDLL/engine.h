#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine(QObject * parent = nullptr);
    ~Engine();
     void getDataFromDB();
     QString dataFromDB;
     void postLoginFromDB(QNetworkReply *reply);

private:
    QByteArray response_data;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QString pin;

    QNetworkAccessManager *dbManager;

signals:
    void sendToMainClass(QString);


public slots:


private slots:
    //void dbSlot();
    //void loginSlot(QNetworkReply *reply);
};

#endif // ENGINE_H
