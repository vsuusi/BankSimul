/********************************************************************************
** Form generated from reading UI file 'dialogpin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPIN_H
#define UI_DIALOGPIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogPin
{
public:
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_12;

    void setupUi(QDialog *DialogPin)
    {
        if (DialogPin->objectName().isEmpty())
            DialogPin->setObjectName(QString::fromUtf8("DialogPin"));
        DialogPin->resize(400, 300);
        lineEdit = new QLineEdit(DialogPin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 113, 28));
        lineEdit->setAcceptDrops(true);
        lineEdit->setToolTipDuration(0);
        lineEdit->setMaxLength(4);
        lineEdit->setFrame(true);
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setCursorPosition(0);
        lineEdit->setReadOnly(false);
        lineEdit->setClearButtonEnabled(false);
        layoutWidget = new QWidget(DialogPin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 110, 262, 141));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout_2->addWidget(pushButton_8);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout_2->addWidget(pushButton_10);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout_3->addWidget(pushButton_9);

        pushButton_12 = new QPushButton(layoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout_3->addWidget(pushButton_12);


        gridLayout->addLayout(verticalLayout_3, 0, 2, 1, 1);


        retranslateUi(DialogPin);

        QMetaObject::connectSlotsByName(DialogPin);
    } // setupUi

    void retranslateUi(QDialog *DialogPin)
    {
        DialogPin->setWindowTitle(QCoreApplication::translate("DialogPin", "Dialog", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QString());
        pushButton->setText(QCoreApplication::translate("DialogPin", "1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("DialogPin", "4", nullptr));
        pushButton_7->setText(QCoreApplication::translate("DialogPin", "7", nullptr));
        pushButton_11->setText(QCoreApplication::translate("DialogPin", "<--", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogPin", "2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("DialogPin", "5", nullptr));
        pushButton_8->setText(QCoreApplication::translate("DialogPin", "8", nullptr));
        pushButton_10->setText(QCoreApplication::translate("DialogPin", "0", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DialogPin", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("DialogPin", "6", nullptr));
        pushButton_9->setText(QCoreApplication::translate("DialogPin", "9", nullptr));
        pushButton_12->setText(QCoreApplication::translate("DialogPin", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPin: public Ui_DialogPin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPIN_H
