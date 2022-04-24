#ifndef PINBTNS_H
#define PINBTNS_H

#include <QWidget>

namespace Ui {
class PinBtns;
}

class PinBtns : public QWidget
{
    Q_OBJECT

public:
    explicit PinBtns(QWidget *parent = nullptr);
    ~PinBtns();

private:
    Ui::PinBtns *ui;
};

#endif // PINBTNS_H
