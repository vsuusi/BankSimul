#include "pininterface.h"
#include "ui_pininterface.h"

pinInterface::pinInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinInterface)
{
    ui->setupUi(this);
    objectkayttoliittyma = new kayttoliittyma;

    pinAjastin = new QTimer(this);
    connect(pinAjastin, SIGNAL(timeout()),
            this, SLOT(timeoutPinUi()));
    pinAjastin->start(10000);

}

pinInterface::~pinInterface()
{
    delete ui;
    delete objectkayttoliittyma;

    ui = nullptr;
    objectkayttoliittyma = nullptr;
}

void pinInterface::on_btn_pinKirjaudu_clicked()
{
    objectkayttoliittyma->show();
}

void pinInterface::timeoutPinUi()
{
    this->close();
}

