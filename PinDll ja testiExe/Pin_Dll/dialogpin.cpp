#include "dialogpin.h"
#include "ui_dialogpin.h"

DialogPin::DialogPin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPin)

{
    ui->setupUi(this);

}

DialogPin::~DialogPin()
{
    delete ui;
    ui=nullptr;
}

void DialogPin::on_pushButton_clicked()
{
    QString a = "1";
    ui->lineEdit->insert(a);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_2_clicked()
{
    QString b= "2";
    ui->lineEdit->insert(b);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_3_clicked()
{
    QString c= "3";
    ui->lineEdit->insert(c);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_4_clicked()
{
    QString d= "4";
    ui->lineEdit->insert(d);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_5_clicked()
{
    QString e= "5";
    ui->lineEdit->insert(e);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_6_clicked()
{
    QString f= "6";
    ui->lineEdit->insert(f);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_7_clicked()
{
    QString g= "7";
    ui->lineEdit->insert(g);
    QString pin = ui->lineEdit->text( );
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_8_clicked()
{
    QString h= "8";
    ui->lineEdit->insert(h);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);

}


void DialogPin::on_pushButton_9_clicked()
{
    QString i= "9";
    ui->lineEdit->insert(i);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}


void DialogPin::on_pushButton_10_clicked()
{
    QString j= "0";
    ui->lineEdit->insert(j);
    QString pin = ui->lineEdit->text();
    this->setDialogPinValue(pin);
}

void DialogPin::on_pushButton_11_clicked()
{
    ui->lineEdit->clear();
    this->setDialogPinValue("");
}

void DialogPin::on_pushButton_12_clicked()
{
    this->close();
}

const QString &DialogPin::getDialogPinValue() const
{
    return dialogPinValue;
}

void DialogPin::setDialogPinValue(const QString &newDialogPinValue)
{
    dialogPinValue = newDialogPinValue;
}










