#include "nostoikkuna.h"
#include "ui_nostoikkuna.h"

nostoikkuna::nostoikkuna(double kayttissaldo, QByteArray kayttisToken, int NostoTiliId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nostoikkuna)
{
    ui->setupUi(this);
    objNostoApi = new ApiDLL(this);
    connect(objNostoApi, SIGNAL(sendTilitapahtumatToExe(QString)),
            this, SLOT(reciveTilitapahtumatInNosto(QString)));

    nostoToken = kayttisToken;
    idtili = NostoTiliId;
    saldo = kayttissaldo;
}

nostoikkuna::~nostoikkuna()
{
    delete ui;
    delete objNostoApi;
    ui = nullptr;
    objNostoApi = nullptr;
}


//void nostoikkuna::reciveTili(QString tili_dataId, QString tili_dataNumero, QString tili_dataSaldo)
//{
//    saldo = tili_dataSaldo.toDouble();
//}


void nostoikkuna::on_btn_nosta20_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 20€?");
    nostoSumma = 20;
}


void nostoikkuna::on_btn_nosta40_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 40€?");
    nostoSumma = 40;
}


void nostoikkuna::on_btn_nosta50_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 50€?");
    nostoSumma = 50;
}


void nostoikkuna::on_btn_nosta100_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 100€?");
    nostoSumma = 100;
}


void nostoikkuna::on_btn_vahvistaNosto_clicked()
{

    if (nostoSumma > saldo)
    {
    QString saldo_str = QString::number(saldo);
    ui->lineEdit_nostetaanSummaX->setText("Tilillä ei ole tarpeeksi katetta."
                                          " Tilin saldo: " + saldo_str);
    }

    else
    {

    saldo = saldo - nostoSumma;
    QString nostoSumma_str = QString::number(nostoSumma);
    QString saldo_str = QString::number(saldo);
    ui->lineEdit_nostetaanSummaX->setText("Nostetaan " + nostoSumma_str +
                                                "€. Tilin saldo: " + saldo_str + "€");

    objNostoApi->UpdateTili(nostoToken, saldo, idtili);
    objNostoApi->Tilitapahtumat(nostoToken, idtili);
    emit updateSaldoSignal(saldo);
    this->close();
    }

}

void nostoikkuna::on_btn_peruutaNosto_clicked()
{
    ui->lineEdit_nostetaanSummaX->clear();
    this->close();
}

void nostoikkuna::reciveTilitapahtumatInNosto(QString tilitapahtumat_data)
{
    QStringList tapahtumaList = tilitapahtumat_data.split(",");
    QString idtilitapah = tapahtumaList.value(tapahtumaList.length()-6);
    idtilitapahtumat = idtilitapah.toInt();

    QString tapahtuma = "Nosto";
    QDateTime paivaysDT = QDateTime::currentDateTime();
    // QString paivays2 = QDateTime::currentDateTime().toTimeSpec(Qt::OffsetFromUTC).toString(Qt::ISODate);
    QString paivays = paivaysDT.toString("yyyy-MM-dd hh:mm:ss");

    double summa = nostoSumma;
    int idkortti = idtili;
    qDebug() << "idtili: " + QString::number(idtili) + "idtilitapahtumat: " + QString::number(idtilitapahtumat);
    objNostoApi->addTilitapahtumat(nostoToken,idtilitapahtumat, paivays, tapahtuma, summa, idkortti, idtili);
    idtilitapahtumat++;
}


