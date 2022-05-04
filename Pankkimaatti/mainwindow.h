#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QMainWindow>
#include "pininterface.h"
#include <QDebug>
#include "lukija_dll.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_syotakortti_clicked();
    void reciveRFID(QString response);

private:
    Ui::MainWindow *ui;
    pinInterface *objectpinInterface;
};
#endif // MAINWINDOW_H
