#include "pininterface.h"
#include "ui_pininterface.h"


pinInterface::pinInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinInterface)
{
    ui->setupUi(this);
    pinAjastin = new QTimer(this);

    objLukija = new Lukija_Dll(this);
        connect(objLukija,SIGNAL(sendValueToExe(QString)),
                this,SLOT(reciveRFID(QString)));

    objPinApi = new ApiDLL(this);
        connect(objPinApi, SIGNAL(sendTokenToExe(QByteArray)),
                this, SLOT(reciveToken(QByteArray)));

      ui->lineEdit_korttinumero->hide();

}

pinInterface::~pinInterface()
{
    delete ui;
    delete objectkayttoliittyma;
    delete pinAjastin;
    delete objLukija;
    delete objPinApi;

    pinAjastin = nullptr;
    ui = nullptr;
    objectkayttoliittyma = nullptr;
    objLukija = nullptr;
    objPinApi = nullptr;
}

void pinInterface::timeoutPinUi()
{
    this->close();
    ui->lineEdit_pinSyotto->clear();
        qDebug() << "ajastin sulkee pin ui:n";

}
void pinInterface::reciveRFID(QString response)
{
    korttinumero = response;
}



void pinInterface::reciveToken(QByteArray token)
{
    EXEtoken = token;
    emit QuitEventLoop();
}


void pinInterface::on_btn_pinKirjaudu_clicked()
{
    pin = ui->lineEdit_pinSyotto->text();
    // korttinumero = ui->lineEdit_korttinumero->text();
    objPinApi->Login(pin, korttinumero);

    if(korttinumero == "0500"){
        asiakasId = 1;
    }
    if(korttinumero == "0600"){
        asiakasId = 2;
        }

    QEventLoop loop;
    connect(this, &pinInterface::QuitEventLoop, &loop, &QEventLoop::quit);
    loop.exec();
    qDebug() << "Exetoken eventloopin jalkeen: " + EXEtoken;


    if (EXEtoken != "Bearer false")
    {
        objectkayttoliittyma = new kayttoliittyma(EXEtoken, asiakasId);
        this->close();
        pinAjastin->stop();
        qDebug() << "pin ui suljettu";
        clearWrongPasswordLabel();
        objectkayttoliittyma->exec();
    }

    else
    {
       ui->label_wrongPass->setText("Salasana väärin!");
       pinAjastin->stop();
       pinAjastin->start(15000);
       qDebug() << "pin ajastin restart";
    }

    ui->lineEdit_pinSyotto->clear();
}

void pinInterface::clearWrongPasswordLabel()
{

    ui->label_wrongPass->clear();
}

