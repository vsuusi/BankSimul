#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pLukija_Dll = new Lukija_Dll(this);
    connect(pLukija_Dll,SIGNAL(sendValueToExe(QString)),
            this,SLOT(showLabel(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pLukija_Dll;
    pLukija_Dll = nullptr;
}

void MainWindow::showLabel(QString response)
{
    qDebug() <<response;
    ui->label->setText(response);

}

