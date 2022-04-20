#ifndef LUKIJA_DLL_ENGINE_H
#define LUKIJA_DLL_ENGINE_H


#include <QObject>
#include <QSerialPort>
#include <QByteArray>
#include <QDebug>

class Lukija_Dll_Engine : public QObject
{
    Q_OBJECT
public:
    Lukija_Dll_Engine(QObject *parent = nullptr);
    ~Lukija_Dll_Engine();





    QByteArray ba;
    QString response;

private slots:

    void recvResponse();


private:
    QByteArray data;


signals:

    void returnValueToLukija_Dll(QString);
    void readyRead();
};



#endif // LUKIJA_DLL_ENGINE_H
