#include "tapahtumavirta.h"
#include "ui_tapahtumavirta.h"

tapahtumavirta::tapahtumavirta(QByteArray kayttisToken, int NostoTiliId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tapahtumavirta)
{

    ui->setupUi(this);
    ui->listWidget_tilitapahtumat->hide();
    //ui->textEdit_tapahtumavirta->hide();
    objVirtaApi = new ApiDLL(this);
    objVirtaApi->Tilitapahtumat(kayttisToken, NostoTiliId);
    connect(objVirtaApi, SIGNAL(sendTilitapahtumatToExe(QString)),
            this, SLOT(reciveTilitapahtumat(QString)));


//    for (int i=0; i<30; i++)
//        ui->listWidget_tilitapahtumat->addItem("Tilitapahtuma 0" + QString::number(i));
//    ui->listWidget_tilitapahtumat->sortItems(Qt::AscendingOrder); // eri order kun oikea data

}

tapahtumavirta::~tapahtumavirta()
{
    delete objVirtaApi;
    delete ui;
    objVirtaApi = nullptr;
}

void tapahtumavirta::reciveTilitapahtumat(QString tilitapahtumat_data)
{

    QStringList tapahtumaList = tilitapahtumat_data.split(",");

    for(int i=0; i<tapahtumaList.size();i=i+3){
        tapahtumaList.removeAt(i);
    }
//    for (int i=1; i<tapahtumaList.size();i=i+3){
//        tapahtumaList.at(i).;
//        date.chop(4);
//        qDebug()<< "indexiluku2: " + QString::number(i);
//    }
    QString list = tapahtumaList.join(",");
    ui->textEdit_tapahtumavirta->setText(list);

}

void tapahtumavirta::on_btn_tilitapahtumatPaluu_clicked()
{
    this->close();
}


void tapahtumavirta::on_btn_edellisetTapahtumat_clicked()
{
    ui->textEdit_tapahtumavirta->scrollToAnchor("10");
}


void tapahtumavirta::on_btn_seuraavatTapahtumat_clicked()
{
    ui->textEdit_tapahtumavirta->scrollToAnchor("1");
}

