#include "pinbtns.h"
#include "ui_pinbtns.h"

PinBtns::PinBtns(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PinBtns)
{
    ui->setupUi(this);
}

PinBtns::~PinBtns()
{
    delete ui;
}
