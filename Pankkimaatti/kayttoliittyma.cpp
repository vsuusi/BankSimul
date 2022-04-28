#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"


kayttoliittyma::kayttoliittyma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kayttoliittyma)
{
    ui->setupUi(this);
    objectnostoikkuna = new nostoikkuna;
    objecttapahtumavirta = new tapahtumavirta;
    objKayttoApi = new ApiDLL(this);


//    connect(objKayttoApi,SIGNAL(sendToExe()),
//            this,SLOT(recvTiliFromDB()));

//    connect(objKayttoApi, SIGNAL(sendToExe(tili)),
//            this,SLOT(recvTiliFromDB()));

    ui->label_tilinSaldo->setText(QString::number(objectnostoikkuna->saldo));

}

kayttoliittyma::~kayttoliittyma()
{
    delete ui;
    delete objectnostoikkuna;
    delete objecttapahtumavirta;
    delete objKayttoApi;


    ui = nullptr;
    objectnostoikkuna = nullptr;
    objecttapahtumavirta = nullptr;
    objKayttoApi = nullptr;

}




/****************buttons**********************/



void kayttoliittyma::on_btn_nostaRahaa_clicked()
{

    objectnostoikkuna->exec();
    ui->label_tilinSaldo->setText(objectnostoikkuna->getSaldo());
}


void kayttoliittyma::on_btn_tilitapahtumat_clicked()
{
    objecttapahtumavirta->exec();
}


void kayttoliittyma::on_btn_kirjauduUlos_clicked()
{
    this->close();
    delete this;


    // ja katkaise yhteystietokantaan
}



