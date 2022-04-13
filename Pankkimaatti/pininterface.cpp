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
    // delete pinAjastin;

    //pinAjastin = nullptr;
    ui = nullptr;
    objectkayttoliittyma = nullptr;
}

void pinInterface::timeoutPinUi()
{
    this->close();
        qDebug() << "ajastin sulkee pin ui:n";

}


void pinInterface::on_btn_pinKirjaudu_clicked()
{
    // pinAjastin->stop();
    pinAjastin->start(15000);
    qDebug() << "pin ajastin restartattu 15s";

    // tarkista tietokannasta onko salasana oikein, jos on:
    // tässä hardkoodattu password = pass

    if (ui->lineEdit_pinSyotto->text() == password)
    {
        this->close();
        qDebug() << "salasana oikein, pinUI suljettu ja timer tuhottu";
        delete pinAjastin;
        pinAjastin = nullptr;

        objectkayttoliittyma->exec();



    }

    else
    {
        ui->label_wrongPass->setText("Salasana väärin!");
    }
    ui->lineEdit_pinSyotto->clear();
}


