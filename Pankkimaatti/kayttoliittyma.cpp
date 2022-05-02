#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"


kayttoliittyma::kayttoliittyma(QByteArray EXEtoken, int asiakasId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kayttoliittyma)
{
    ui->setupUi(this);

    kayttisToken = EXEtoken;

    objKayttoApi = new ApiDLL(this);
    objKayttoApi->Asiakas(kayttisToken, asiakasId);


    connect(objKayttoApi, SIGNAL(sendAsiakasToExe(QString)),
            this, SLOT(reciveAsiakas(QString)));
    connect(objKayttoApi, SIGNAL(sendTiliToExe(QString, QString, QString)),
            this, SLOT(reciveTili(QString,QString,QString)));

    QEventLoop loop;
    connect(this, &kayttoliittyma::QuitEventLoopTili, &loop, &QEventLoop::quit);
    loop.exec();
    objKayttoApi->Tili(kayttisToken, asiakasId);
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

void kayttoliittyma::reciveAsiakas(QString RAasiakas)
{
    nykyinenAsiakas = RAasiakas;
    // nykyinenAsiakas.remove(0,2);
    QStringList palat = nykyinenAsiakas.split(",");
    QString nykyinenAsiakasTrimmed = palat.value(palat.length()- 3);
    qDebug()<< "nykyinen asiakas: " + nykyinenAsiakasTrimmed;
    ui->label_asiakasNimi->setText(nykyinenAsiakasTrimmed);
    QString asiakasId = palat.value(palat.length()-4);
    qDebug()<< "asiakas id: " + asiakasId;
    objectnostoikkuna = new nostoikkuna;
    objecttapahtumavirta = new tapahtumavirta;
    emit QuitEventLoopTili();
}

void kayttoliittyma::reciveTili(QString tili_dataId, QString tili_dataNumero, QString tili_dataSaldo)
{

    qDebug() << "tilidata exessä:" + tili_dataId + tili_dataNumero + tili_dataSaldo;
    saldo = tili_dataSaldo;
    tilinumero = tili_dataNumero;
    idtili = tili_dataId;
    ui->label_tilinSaldo->setText(saldo);


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



