#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectPin_Dll=new Pin_Dll;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectPin_Dll;
    objectPin_Dll=nullptr;
}


void MainWindow::on_pushButton_clicked()
{

    objectPin_Dll->openDllDialog();
    QString value=objectPin_Dll->returnFromDll();
    ui->textValue->setText(value);


}

