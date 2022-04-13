#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectpinInterface = new pinInterface;    

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectpinInterface;

    ui = nullptr;
    objectpinInterface = nullptr;
}

//void MainWindow::timeoutPinUi()
//{
//    objectpinInterface->close();
//        qDebug() << "ajastin sulkee pin ui:n";

//}


void MainWindow::on_btn_syotakortti_clicked()
{

    connect(objectpinInterface->pinAjastin, SIGNAL(timeout()),
            objectpinInterface, SLOT(timeoutPinUi()));

    objectpinInterface->pinAjastin->start(15000);
        qDebug() << "pin ajastin käyntiin 15 sec";

    objectpinInterface->exec();


}


