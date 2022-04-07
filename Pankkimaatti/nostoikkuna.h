#ifndef NOSTOIKKUNA_H
#define NOSTOIKKUNA_H

#include <QDialog>

namespace Ui {
class nostoikkuna;
}

class nostoikkuna : public QDialog
{
    Q_OBJECT

public:
    explicit nostoikkuna(QWidget *parent = nullptr);
    ~nostoikkuna();

private slots:
    void on_btn_nosta20_clicked();

    void on_btn_nosta40_clicked();

    void on_btn_nosta50_clicked();

    void on_btn_nosta100_clicked();



    void on_btn_vahvistaNosto_clicked();

    void on_btn_peruutaNosto_clicked();

private:
    Ui::nostoikkuna *ui;
};

#endif // NOSTOIKKUNA_H
