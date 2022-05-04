#ifndef KAYTTOLIITTYMA_H
#define KAYTTOLIITTYMA_H

#include "nostoikkuna.h"
#include "tapahtumavirta.h"
#include "apidll.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QDialog>
#include <QDebug>
#include <QTimer>

namespace Ui {
class kayttoliittyma;
}

class kayttoliittyma : public QDialog
{
    Q_OBJECT

public:
    explicit kayttoliittyma(QByteArray EXEtoken, int asiakasId, QWidget *parent = nullptr);
    ~kayttoliittyma();

    QString nykyinenAsiakas;
    QByteArray kayttisToken;
    QString saldo_str;
    double saldo;
    QString idtili;
    QString tilinumero;
    int NostoTiliId;

private slots:
    void reciveAsiakas(QString RAasiakas);
    void reciveTili(QString tili_dataId, QString tili_dataNumero, QString tili_dataSaldo);

    void on_btn_nostaRahaa_clicked();
    void on_btn_tilitapahtumat_clicked();
    void on_btn_kirjauduUlos_clicked();

    void updateSaldoSlot(double saldo);

    void timeoutKayttisSlot();
    void StartKayttisSlot();

signals:
    void QuitEventLoopTili();
private:
    Ui::kayttoliittyma *ui;
    nostoikkuna *objectnostoikkuna;
    tapahtumavirta *objecttapahtumavirta;
    ApiDLL *objKayttoApi;
    QTimer *kayttisTimer;

};

#endif // KAYTTOLIITTYMA_H
