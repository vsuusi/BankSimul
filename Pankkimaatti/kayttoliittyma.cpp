#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"

kayttoliittyma::kayttoliittyma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kayttoliittyma)
{
    ui->setupUi(this);
    objectnostoikkuna = new nostoikkuna;
    objecttapahtumavirta = new tapahtumavirta;
    ui->label_tilinSaldo->setText(QString::number(objectnostoikkuna->saldo));
}

kayttoliittyma::~kayttoliittyma()
{
    delete ui;
    delete objectnostoikkuna;
    delete objecttapahtumavirta;

    ui = nullptr;
    objectnostoikkuna = nullptr;
    objecttapahtumavirta = nullptr;
}


void kayttoliittyma::on_btn_nostaRahaa_clicked()
{
    objectnostoikkuna->exec();
}


void kayttoliittyma::on_btn_tilitapahtumat_clicked()
{
    objecttapahtumavirta->exec();
}


void kayttoliittyma::on_btn_kirjauduUlos_clicked()
{
    this->close();
    // ja katkaise yhteystietokantaan
}



