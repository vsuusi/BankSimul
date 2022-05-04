#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "kayttoliittyma.h"
#include "lukija_dll.h"
#include "apidll.h"
#include "pin_dll.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>


namespace Ui {
class pinInterface;
}

class pinInterface : public QDialog
{
    Q_OBJECT

public:
    explicit pinInterface(QWidget *parent = nullptr);
    ~pinInterface();
     QTimer *pinAjastin;
     Lukija_Dll *objLukija;
     int asiakasId;

public slots:
     void timeoutPinUi();

private slots:
    void on_btn_pinKirjaudu_clicked();
    void reciveRFID(QString response);
    void reciveToken(QByteArray token);

signals:
    void QuitEventLoop();


private:
    void clearWrongPasswordLabel();
    Ui::pinInterface *ui;
    kayttoliittyma *objectkayttoliittyma;
    ApiDLL *objPinApi;

    QString idkortti;
    QString korttinumero;
    QString pin;

    QByteArray EXEtoken;
    QByteArray token;




};

#endif // PININTERFACE_H
