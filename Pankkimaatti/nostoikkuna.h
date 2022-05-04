#ifndef NOSTOIKKUNA_H
#define NOSTOIKKUNA_H


#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "apidll.h"


namespace Ui {

class nostoikkuna;
}

class nostoikkuna : public QDialog
{
    Q_OBJECT

public:
    explicit nostoikkuna(double kayttissaldo, QByteArray kayttisToken, int NostoTiliId, QWidget *parent = nullptr);
    ~nostoikkuna();

signals:
    void updateSaldoSignal(double saldo);

private slots:    
    //void reciveTili(QString tili_dataId, QString tili_dataNumero, QString tili_dataSaldo);

    void on_btn_nosta20_clicked();
    void on_btn_nosta40_clicked();
    void on_btn_nosta50_clicked();
    void on_btn_nosta100_clicked();

    void on_btn_vahvistaNosto_clicked();
    void on_btn_peruutaNosto_clicked();

    void reciveTilitapahtumatInNosto(QString tilitapahtumat_data);
private:
    Ui::nostoikkuna *ui;
    ApiDLL *objNostoApi;
    QByteArray nostoToken;
    int idtili;
    double saldo;
    double nostoSumma;
    int idtilitapahtumat;

};

#endif // NOSTOIKKUNA_H
