#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectpinInterface = new pinInterface;
//    objLukija = new Lukija_Dll(this);
        connect(objectpinInterface->objLukija,SIGNAL(sendValueToExe(QString)),
                this,SLOT(reciveRFID(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectpinInterface;

    ui = nullptr;
    objectpinInterface = nullptr;
}


void MainWindow::on_btn_syotakortti_clicked()
{

    connect(objectpinInterface->pinAjastin, SIGNAL(timeout()),
            objectpinInterface, SLOT(timeoutPinUi()));
    objectpinInterface->pinAjastin->setSingleShot(true);

    objectpinInterface->pinAjastin->start(15000);
        qDebug() << "pin ajastin käyntiin 15 sec";


    objectpinInterface->exec();

}

void MainWindow::reciveRFID(QString response)
{
    // if (response == "06000DE56B") {|| "0500CCA4A1")


    qDebug() << response;
    connect(objectpinInterface->pinAjastin, SIGNAL(timeout()),
            objectpinInterface, SLOT(timeoutPinUi()));

    objectpinInterface->pinAjastin->start(15000);
        qDebug() << "pin ajastin käyntiin 15 sec";
    objectpinInterface->exec();

}


