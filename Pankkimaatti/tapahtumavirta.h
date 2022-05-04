#ifndef TAPAHTUMAVIRTA_H
#define TAPAHTUMAVIRTA_H

#include <QDialog>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "apidll.h"

namespace Ui {
class tapahtumavirta;
}

class tapahtumavirta : public QDialog
{
    Q_OBJECT

public:
    explicit tapahtumavirta(QByteArray kayttisToken, int NostoTiliId, QWidget *parent = nullptr);
    ~tapahtumavirta();
signals:
    void StartKayttisTimerSignal();

private slots:
    void reciveTilitapahtumat(QString tilitapahtumat_data);

    void on_btn_tilitapahtumatPaluu_clicked();
    void on_btn_edellisetTapahtumat_clicked();
    void on_btn_seuraavatTapahtumat_clicked();

private:
    Ui::tapahtumavirta *ui;
    ApiDLL *objVirtaApi;
    QString tilitapahtumat_data;
    int scrollanchor = 10;
};

#endif // TAPAHTUMAVIRTA_H
