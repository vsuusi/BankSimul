#ifndef TAPAHTUMAVIRTA_H
#define TAPAHTUMAVIRTA_H

#include <QDialog>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class tapahtumavirta;
}

class tapahtumavirta : public QDialog
{
    Q_OBJECT

public:
    explicit tapahtumavirta(QWidget *parent = nullptr);
    ~tapahtumavirta();

private slots:
    void on_btn_tilitapahtumatPaluu_clicked();

private:
    Ui::tapahtumavirta *ui;
};

#endif // TAPAHTUMAVIRTA_H
