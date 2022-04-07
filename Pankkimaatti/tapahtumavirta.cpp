#include "tapahtumavirta.h"
#include "ui_tapahtumavirta.h"

tapahtumavirta::tapahtumavirta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tapahtumavirta)
{
    ui->setupUi(this);
}

tapahtumavirta::~tapahtumavirta()
{
    delete ui;
}

void tapahtumavirta::on_btn_tilitapahtumatPaluu_clicked()
{
    this->close();
}

 // scroll box tähän?
 // style sheets
