#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "kayttoliittyma.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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
     QTimer *pinAjastin;
public slots:



private slots:
    void on_btn_pinKirjaudu_clicked();



private:
    Ui::pinInterface *ui;
    kayttoliittyma *objectkayttoliittyma;
    QString password = "pass";              // SALASANA !!

};

#endif // PININTERFACE_H
