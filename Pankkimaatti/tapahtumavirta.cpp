#include "tapahtumavirta.h"
#include "ui_tapahtumavirta.h"

tapahtumavirta::tapahtumavirta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tapahtumavirta)
{
    ui->setupUi(this);

    for (int i=0; i<30; i++)
        ui->listWidget_tilitapahtumat->addItem("Tilitapahtuma 0" + QString::number(i));
    ui->listWidget_tilitapahtumat->sortItems(Qt::AscendingOrder); // eri order kun oikea data
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

void tapahtumavirta::on_btn_edellisetTapahtumat_clicked()
{
    ui->listWidget_tilitapahtumat->scrollToBottom();
}


void tapahtumavirta::on_btn_seuraavatTapahtumat_clicked()
{
    ui->listWidget_tilitapahtumat->scrollToTop();
}

