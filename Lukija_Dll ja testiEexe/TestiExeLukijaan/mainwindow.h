#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void showLabel(QString);

signals:

    void sendValueToExe(QString response);

private:
    Ui::MainWindow *ui;
    Lukija_Dll * pLukija_Dll;
    QString response;
    QByteArray ba;

};
#endif // MAINWINDOW_H
