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

void nostoikkuna::on_btn_nosta20_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 20€");
}


void nostoikkuna::on_btn_nosta40_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 40€");
}


void nostoikkuna::on_btn_nosta50_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 50€");
}


void nostoikkuna::on_btn_nosta100_clicked()
{
    ui->lineEdit_nostetaanSummaX->setText("Nostetaanko 100€");
}


void nostoikkuna::on_btn_vahvistaNosto_clicked()
{

}


void nostoikkuna::on_btn_peruutaNosto_clicked()
{
    this->close();
}

