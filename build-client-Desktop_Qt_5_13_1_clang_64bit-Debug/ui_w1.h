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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W1
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *username_label;
    QLineEdit *username_le;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password_label;
    QLineEdit *password_le;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *login_pb;
    QPushButton *regist_pb;
    QSpacerItem *horizontalSpacer_2;
    QLabel *wft;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *W1)
    {
        if (W1->objectName().isEmpty())
            W1->setObjectName(QString::fromUtf8("W1"));
        W1->resize(400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(W1->sizePolicy().hasHeightForWidth());
        W1->setSizePolicy(sizePolicy);
        W1->setMinimumSize(QSize(400, 400));
        W1->setMaximumSize(QSize(400, 400));
        verticalLayout_3 = new QVBoxLayout(W1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        username_label = new QLabel(W1);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        QFont font;
        font.setPointSize(18);
        username_label->setFont(font);

        horizontalLayout->addWidget(username_label);

        username_le = new QLineEdit(W1);
        username_le->setObjectName(QString::fromUtf8("username_le"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(username_le->sizePolicy().hasHeightForWidth());
        username_le->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(username_le);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        password_label = new QLabel(W1);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setFont(font);

        horizontalLayout_2->addWidget(password_label);

        password_le = new QLineEdit(W1);
        password_le->setObjectName(QString::fromUtf8("password_le"));
        password_le->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password_le);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        login_pb = new QPushButton(W1);
        login_pb->setObjectName(QString::fromUtf8("login_pb"));

        horizontalLayout_3->addWidget(login_pb);

        regist_pb = new QPushButton(W1);
        regist_pb->setObjectName(QString::fromUtf8("regist_pb"));

        horizontalLayout_3->addWidget(regist_pb);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        wft = new QLabel(W1);
        wft->setObjectName(QString::fromUtf8("wft"));
        wft->setLayoutDirection(Qt::LeftToRight);
        wft->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(wft);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(W1);

        QMetaObject::connectSlotsByName(W1);
    } // setupUi

    void retranslateUi(QWidget *W1)
    {
        W1->setWindowTitle(QCoreApplication::translate("W1", "W1", nullptr));
        username_label->setText(QCoreApplication::translate("W1", "username", nullptr));
        password_label->setText(QCoreApplication::translate("W1", "password", nullptr));
        login_pb->setText(QCoreApplication::translate("W1", "\347\231\273\345\275\225", nullptr));
        regist_pb->setText(QCoreApplication::translate("W1", "\346\263\250\345\206\214", nullptr));
        wft->setText(QCoreApplication::translate("W1", "\346\234\252\350\277\236\346\216\245\350\207\263\346\234\215\345\212\241\345\231\250\357\274\214\350\257\267\346\243\200\346\237\245\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W1: public Ui_W1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W1_H
