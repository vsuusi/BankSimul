#ifndef KAYTTOLIITTYMA_H
#define KAYTTOLIITTYMA_H

#include "nostoikkuna.h"
#include "tapahtumavirta.h"

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
    explicit kayttoliittyma(QWidget *parent = nullptr);
    ~kayttoliittyma();

public slots:
    // void updateSaldoSlot();



private slots:
    void on_btn_nostaRahaa_clicked();

    void on_btn_tilitapahtumat_clicked();

    void on_btn_kirjauduUlos_clicked();


private:

    Ui::kayttoliittyma *ui;
    nostoikkuna *objectnostoikkuna;
    tapahtumavirta *objecttapahtumavirta;


};

#endif // KAYTTOLIITTYMA_H
