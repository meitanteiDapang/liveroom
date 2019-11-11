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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QLineEdit *ip_le;
    QLineEdit *port_le;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *udp_label;
    QLineEdit *port_le_2;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *W1)
    {
        if (W1->objectName().isEmpty())
            W1->setObjectName(QString::fromUtf8("W1"));
        W1->resize(800, 600);
        tb = new QTextBrowser(W1);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(25, 211, 741, 351));
        label = new QLabel(W1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(47, 70, 111, 20));
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
        ip_le = new QLineEdit(W1);
        ip_le->setObjectName(QString::fromUtf8("ip_le"));
        ip_le->setGeometry(QRect(130, 160, 113, 24));
        port_le = new QLineEdit(W1);
        port_le->setObjectName(QString::fromUtf8("port_le"));
        port_le->setGeometry(QRect(300, 140, 113, 24));
        pushButton = new QPushButton(W1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 160, 161, 24));
        label_3 = new QLabel(W1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 91, 16));
        udp_label = new QLabel(W1);
        udp_label->setObjectName(QString::fromUtf8("udp_label"));
        udp_label->setGeometry(QRect(170, 90, 121, 61));
        udp_label->setFont(font);
        port_le_2 = new QLineEdit(W1);
        port_le_2->setObjectName(QString::fromUtf8("port_le_2"));
        port_le_2->setGeometry(QRect(300, 170, 113, 24));
        label_4 = new QLabel(W1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 140, 58, 16));
        label_5 = new QLabel(W1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 170, 58, 16));

        retranslateUi(W1);

        QMetaObject::connectSlotsByName(W1);
    } // setupUi

    void retranslateUi(QWidget *W1)
    {
        W1->setWindowTitle(QCoreApplication::translate("W1", "W1", nullptr));
        label->setText(QCoreApplication::translate("W1", "tcp\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        status_label->setText(QCoreApplication::translate("W1", "\346\234\252\347\233\221\345\220\254", nullptr));
        label_2->setText(QCoreApplication::translate("W1", "\346\225\260\346\215\256\345\272\223\347\212\266\346\200\201", nullptr));
        wft->setText(QString());
        ip_le->setText(QCoreApplication::translate("W1", "127.0.0.1", nullptr));
        port_le->setText(QCoreApplication::translate("W1", "8888", nullptr));
        pushButton->setText(QCoreApplication::translate("W1", "listen and bind", nullptr));
        label_3->setText(QCoreApplication::translate("W1", "upd\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        udp_label->setText(QCoreApplication::translate("W1", "\346\234\252\347\273\221\345\256\232", nullptr));
        port_le_2->setText(QCoreApplication::translate("W1", "8889", nullptr));
        label_4->setText(QCoreApplication::translate("W1", "tcp", nullptr));
        label_5->setText(QCoreApplication::translate("W1", "udp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W1: public Ui_W1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W1_H
