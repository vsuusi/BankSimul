#include "pininterface.h"
#include "ui_pininterface.h"


pinInterface::pinInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinInterface)
{
    ui->setupUi(this);
    objectkayttoliittyma = new kayttoliittyma;
    pinAjastin = new QTimer(this);

}

pinInterface::~pinInterface()
{
    delete ui;
    delete objectkayttoliittyma;
    delete pinAjastin;

    pinAjastin = nullptr;
    ui = nullptr;
    objectkayttoliittyma = nullptr;
}


void pinInterface::on_btn_pinKirjaudu_clicked()
{
    pinAjastin->stop();
    pinAjastin->start(15000);
    qDebug() << "pin ajastin restartattu 15s";

    // tarkista tietokannasta onko salasana oikein, jos on:
    objectkayttoliittyma->exec();
}


