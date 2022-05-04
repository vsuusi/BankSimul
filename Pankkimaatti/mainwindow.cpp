#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectpinInterface = new pinInterface;
    connect(objectpinInterface->objLukija,SIGNAL(sendValueToExe(QString)),
            this,SLOT(reciveRFID(QString)));
    ui->btn_syotakortti->hide();

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

    qDebug() << response;
    connect(objectpinInterface->pinAjastin, SIGNAL(timeout()),
            objectpinInterface, SLOT(timeoutPinUi()));

    objectpinInterface->pinAjastin->start(15000);
        qDebug() << "pin ajastin käyntiin 15 sec";
    objectpinInterface->exec();

}


