#include "nostoikkuna.h"
#include "ui_nostoikkuna.h"

nostoikkuna::nostoikkuna(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nostoikkuna)
{
    ui->setupUi(this);
}

nostoikkuna::~nostoikkuna()
{
    delete ui;
}

QString nostoikkuna::getSaldo()
{
    QString saldo_str = QString::number(saldo);
    return saldo_str;
}


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
    qDebug() << "Tilin saldo: " + saldo_str;
    }

}


void nostoikkuna::on_btn_peruutaNosto_clicked()
{
    ui->lineEdit_nostetaanSummaX->clear();
    this->close();
}


