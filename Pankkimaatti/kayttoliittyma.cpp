#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"


kayttoliittyma::kayttoliittyma(QByteArray EXEtoken, int asiakasId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kayttoliittyma)
{
    ui->setupUi(this);
    kayttisToken = EXEtoken;
    NostoTiliId = asiakasId;

    kayttisTimer = new QTimer(this);
    connect(this->kayttisTimer, SIGNAL(timeout()),
            this, SLOT(timeoutKayttisSlot()));

    kayttisTimer->setSingleShot(true);
    kayttisTimer->start(30000);
        qDebug() << "kayttisTimer startti 30sec";

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
    QStringList palat = nykyinenAsiakas.split(",");
    QString nykyinenAsiakasTrimmed = palat.value(palat.length()- 3);
    QString osoite = palat.value(palat.length()- 2);
    QString puhnro = palat.value(palat.length()- 1);
        // qDebug()<< "nykyinen asiakas: " + nykyinenAsiakasTrimmed;
    ui->label_asiakasNimi->setText(nykyinenAsiakasTrimmed);
    ui->label_osoite->setText(osoite);
    ui->label_puhnro->setText(puhnro);
    QString asiakasId = palat.value(palat.length()-4);
        qDebug()<< "asiakas id: " + asiakasId;

    emit QuitEventLoopTili();
}

void kayttoliittyma::reciveTili(QString tili_dataId, QString tili_dataNumero, QString tili_dataSaldo)
{
        // qDebug() << "tilidata exessä:" + tili_dataId +","+ tili_dataNumero +","+ tili_dataSaldo;
    saldo_str = tili_dataSaldo;
    saldo = saldo_str.toDouble();

    tilinumero = tili_dataNumero;
    idtili = tili_dataId;
    ui->label_tilinSaldo->setText(saldo_str);
}

void kayttoliittyma::updateSaldoSlot(double uusiSaldo)
{
    saldo = uusiSaldo;
    ui->label_tilinSaldo->setText(QString::number(saldo));
}

void kayttoliittyma::timeoutKayttisSlot()
{
    this->close();
    kayttisToken = "";
}

void kayttoliittyma::StartKayttisSlot()
{
    kayttisTimer->start(30000);
        qDebug() << "kayttisTimer tulille niinsanotusti";
}

void kayttoliittyma::on_btn_nostaRahaa_clicked()
{
    kayttisTimer->stop();
        qDebug() << "kayttisTimer stop";
    objectnostoikkuna = new nostoikkuna(saldo, kayttisToken, NostoTiliId);
    connect(objectnostoikkuna, SIGNAL(StartKayttisTimerSignal()),
            this, SLOT(StartKayttisSlot()));

    connect(objectnostoikkuna, SIGNAL(updateSaldoSignal(double)),
            this, SLOT(updateSaldoSlot(double)));
    objectnostoikkuna->exec();
}


void kayttoliittyma::on_btn_tilitapahtumat_clicked()
{
    kayttisTimer->stop();
        qDebug() << "kayttisTimer stop";
    objecttapahtumavirta = new tapahtumavirta(kayttisToken, NostoTiliId);
    connect(objecttapahtumavirta, SIGNAL(StartKayttisTimerSignal()),
            this, SLOT(StartKayttisSlot()));
    objecttapahtumavirta->exec();
}


void kayttoliittyma::on_btn_kirjauduUlos_clicked()
{
    this->close();
    // delete this;
}




