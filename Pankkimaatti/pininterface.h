#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "kayttoliittyma.h"

#include <QDialog>
#include <QDebug>
#include <QTimer>


namespace Ui {
class pinInterface;
}

class pinInterface : public QDialog
{
    Q_OBJECT

public:
    explicit pinInterface(QWidget *parent = nullptr);
    ~pinInterface();

private slots:
    void on_btn_pinKirjaudu_clicked();
    void timeoutPinUi();

private:
    Ui::pinInterface *ui;
    kayttoliittyma *objectkayttoliittyma;
    QTimer *pinAjastin;

};

#endif // PININTERFACE_H
