#include "pininterface.h"
#include "ui_pininterface.h"


pinInterface::pinInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinInterface)
{
    ui->setupUi(this);
    // objectkayttoliittyma = new kayttoliittyma;
    pinAjastin = new QTimer(this);

    objLukija = new Lukija_Dll(this);
        connect(objLukija,SIGNAL(sendValueToExe(QString)),
                this,SLOT(reciveRFID(QString)));

    objPinApi = new ApiDLL(this);
        connect(objPinApi, SIGNAL(sendTokenToExe(QByteArray)),
                this, SLOT(reciveToken(QByteArray)));

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

void pinInterface::timeoutPinUi()
{
    this->close();
        qDebug() << "ajastin sulkee pin ui:n";

}
void pinInterface::reciveRFID(QString response)
{
    korttinumero = response;

    if(korttinumero == "0500"){
        asiakasId = 1;
    }
    if(korttinumero == "0600"){
        asiakasId = 2;
        }
}



void pinInterface::reciveToken(QByteArray token)
{
    EXEtoken = token;
//    qDebug() << EXEtoken;
    emit QuitEventLoop();
}


void pinInterface::on_btn_pinKirjaudu_clicked()
{
    pin = ui->lineEdit_pinSyotto->text();
    objPinApi->Login(pin, korttinumero);
    QEventLoop loop;

    connect(this, &pinInterface::QuitEventLoop, &loop, &QEventLoop::quit);
    loop.exec();
    qDebug() << "Exetoken eventloopin jalkeen: " + EXEtoken;


    if (EXEtoken != "Bearer false")
    {
        objectkayttoliittyma = new kayttoliittyma;
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

