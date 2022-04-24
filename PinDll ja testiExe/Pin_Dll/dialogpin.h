#ifndef DIALOGPIN_H
#define DIALOGPIN_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class DialogPin;
}

class DialogPin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPin(QWidget *parent = nullptr);
    ~DialogPin();



    const QString &getDialogPinValue() const;
    void setDialogPinValue(const QString &newDialogPinValue);

private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

 signals:

    void sendValueToDll();

private:
    Ui::DialogPin *ui;
    QString dialogPinValue;





};

#endif // DIALOGPIN_H
