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


void MainWindow::on_btn_syotakortti_clicked()
{
    objectpinInterface->show();
}

