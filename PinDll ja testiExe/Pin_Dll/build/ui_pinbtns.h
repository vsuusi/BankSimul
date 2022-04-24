/********************************************************************************
** Form generated from reading UI file 'pinbtns.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINBTNS_H
#define UI_PINBTNS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PinBtns
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label;

    void setupUi(QWidget *PinBtns)
    {
        if (PinBtns->objectName().isEmpty())
            PinBtns->setObjectName(QString::fromUtf8("PinBtns"));
        PinBtns->resize(684, 426);
        pushButton = new QPushButton(PinBtns);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 220, 81, 29));
        pushButton_2 = new QPushButton(PinBtns);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 220, 83, 29));
        pushButton_3 = new QPushButton(PinBtns);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 220, 83, 29));
        pushButton_4 = new QPushButton(PinBtns);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 260, 83, 29));
        pushButton_5 = new QPushButton(PinBtns);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 260, 83, 29));
        pushButton_6 = new QPushButton(PinBtns);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(390, 260, 83, 29));
        pushButton_7 = new QPushButton(PinBtns);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(210, 300, 83, 29));
        pushButton_8 = new QPushButton(PinBtns);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(300, 300, 83, 29));
        pushButton_9 = new QPushButton(PinBtns);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(390, 300, 83, 29));
        pushButton_10 = new QPushButton(PinBtns);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(300, 340, 83, 29));
        label = new QLabel(PinBtns);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 160, 261, 20));

        retranslateUi(PinBtns);

        QMetaObject::connectSlotsByName(PinBtns);
    } // setupUi

    void retranslateUi(QWidget *PinBtns)
    {
        PinBtns->setWindowTitle(QCoreApplication::translate("PinBtns", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("PinBtns", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PinBtns", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PinBtns", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PinBtns", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("PinBtns", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("PinBtns", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("PinBtns", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("PinBtns", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("PinBtns", "9", nullptr));
        pushButton_10->setText(QCoreApplication::translate("PinBtns", "0", nullptr));
        label->setText(QCoreApplication::translate("PinBtns", "pin                   ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PinBtns: public Ui_PinBtns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINBTNS_H
