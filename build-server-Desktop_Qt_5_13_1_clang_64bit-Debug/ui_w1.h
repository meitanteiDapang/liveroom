/********************************************************************************
** Form generated from reading UI file 'w1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W1_H
#define UI_W1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W1
{
public:
    QTextBrowser *tb;
    QLabel *label;
    QLabel *status_label;
    QLabel *label_2;
    QLabel *wft;

    void setupUi(QWidget *W1)
    {
        if (W1->objectName().isEmpty())
            W1->setObjectName(QString::fromUtf8("W1"));
        W1->resize(800, 600);
        tb = new QTextBrowser(W1);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(25, 121, 741, 441));
        label = new QLabel(W1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 58, 16));
        status_label = new QLabel(W1);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(180, 25, 121, 61));
        QFont font;
        font.setPointSize(24);
        status_label->setFont(font);
        label_2 = new QLabel(W1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 60, 91, 16));
        wft = new QLabel(W1);
        wft->setObjectName(QString::fromUtf8("wft"));
        wft->setGeometry(QRect(560, 35, 91, 51));
        QFont font1;
        font1.setPointSize(18);
        wft->setFont(font1);

        retranslateUi(W1);

        QMetaObject::connectSlotsByName(W1);
    } // setupUi

    void retranslateUi(QWidget *W1)
    {
        W1->setWindowTitle(QCoreApplication::translate("W1", "W1", nullptr));
        label->setText(QCoreApplication::translate("W1", "\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        status_label->setText(QString());
        label_2->setText(QCoreApplication::translate("W1", "\346\225\260\346\215\256\345\272\223\347\212\266\346\200\201", nullptr));
        wft->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class W1: public Ui_W1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W1_H
